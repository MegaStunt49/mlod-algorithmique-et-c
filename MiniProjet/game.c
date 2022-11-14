//gcc -o game game.c -Wall -std=c11 /home/bot/Raylib.git/src/libraylib.a -lm -lrt -ldl -lX11 -lGL -lpthread

#include "raylib.h"


#include <math.h>
#include <stdio.h>
#include <string.h>


//----------------------------------------------------------------------------------
// Some Defines
//----------------------------------------------------------------------------------
#define PLAYER_BASE_SIZE    20.0f
#define PLAYER_SPEED        6.0f
#define PLAYER_DISTANCE     150

#define MAX_CIRCLES     4

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
typedef struct Player {
    Vector2 position;
    float rotation;
    Vector3 collider;
    Color color;
} Player;


typedef struct Circle {
    Vector2 position;
    float radius;
    Vector2 angle;
    bool active;
    Color color;
} Circle;

//------------------------------------------------------------------------------------
// Global Variables Declaration
//------------------------------------------------------------------------------------
static const int screenWidth = 1000;
static const int screenHeight = 1000;

static int score = 0;
static int highScore = 0;
static bool gameOver = false;
static bool pause = false;
static bool victory = false;

// NOTE: Defined triangle is isosceles with common angles of 70 degrees.
static float shipHeight = 0.0f;

static Player player = { 0 };
static Circle bigCircle[MAX_CIRCLES] = { 0 };

static int destroyedCirclesCount = 0;

//------------------------------------------------------------------------------------
// Module Functions Declaration (local)
//------------------------------------------------------------------------------------
static void InitGame(void);         // Initialize game
static void UpdateGame(void);       // Update game (one frame)
static void DrawGame(void);         // Draw game (one frame)
static void UnloadGame(void);       // Unload game
static void UpdateDrawFrame(void);  // Update and Draw (one frame)

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization (Note windowTitle is unused on Android)
    //---------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "classic game: asteroids");

    InitGame();

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update and Draw
        //----------------------------------------------------------------------------------
        UpdateDrawFrame();
        //----------------------------------------------------------------------------------
    }
#endif
    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadGame();         // Unload loaded data (textures, sounds, models...)

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//------------------------------------------------------------------------------------
// Module Functions Definitions (local)
//------------------------------------------------------------------------------------

// Initialize game variables
void InitGame(void)
{
    int posx, posy;
    victory = false;
    score = 0;
    pause = false;

    shipHeight = (PLAYER_BASE_SIZE/2)/tanf(20*DEG2RAD);

    // Initialization player
    player.position = (Vector2){screenWidth/2, screenHeight/2 - shipHeight/2};
    player.rotation = 0;
    player.collider = (Vector3){player.position.x + sin(player.rotation*DEG2RAD)*(shipHeight/2.5f), player.position.y - cos(player.rotation*DEG2RAD)*(shipHeight/2.5f), 12};
    player.color = LIGHTGRAY;

    destroyedCirclesCount = 0;

    

    for (int i = 0; i < MAX_CIRCLES; i++)
    {   
        int r = GetRandomValue(0, 2);
        posx = GetRandomValue(0, 360);
        posy = posx+325-10*r;

        bigCircle[i].position = (Vector2){screenWidth/2, screenHeight/2};
        bigCircle[i].angle = (Vector2){posx, posy};

        bigCircle[i].radius = i*(-100);
        bigCircle[i].active = false;
        bigCircle[i].color = BLUE;
    }

}

// Update game (one frame)
void UpdateGame(void)
{
    if (!gameOver)
    {
        if (IsKeyPressed('P')) pause = !pause;

        if (!pause)
        {
            // Player logic: rotation
            if (IsKeyDown(KEY_LEFT)) player.rotation -= 5;
            if (IsKeyDown(KEY_RIGHT)) player.rotation += 5;


            // Player logic: movement
            player.position.x = screenWidth/2 + PLAYER_DISTANCE*sin((-1)*player.rotation*DEG2RAD);
            player.position.y = screenHeight/2 + PLAYER_DISTANCE*cos((-1)*player.rotation*DEG2RAD);

            // Collision logic: player vs Circles
            player.collider = (Vector3){player.position.x + sin(player.rotation*DEG2RAD)*(shipHeight/2.5f), player.position.y - cos(player.rotation*DEG2RAD)*(shipHeight/2.5f), 12};

            for (int a = 0; a < MAX_CIRCLES; a++)
            {
                bool angleConforme;
                if (((int)bigCircle[a].angle.x)%360>((int)bigCircle[a].angle.y)%360){
                    angleConforme = (360-(int)player.rotation)%360<((int)bigCircle[a].angle.x)%360 && (360-(int)player.rotation)%360>((int)bigCircle[a].angle.y)%360;
                }
                else{
                    angleConforme = (360-(int)player.rotation)%360<((int)bigCircle[a].angle.x)%360 || (360-(int)player.rotation)%360>((int)bigCircle[a].angle.y)%360;
                }
                if (CheckCollisionCircles((Vector2){player.collider.x, player.collider.y}, player.collider.z, bigCircle[a].position, bigCircle[a].radius) && bigCircle[a].active && bigCircle[a].radius<155){
                    if (angleConforme){
                        if (score%MAX_CIRCLES==a) score++;
                        if (score>highScore) highScore=score;
                    }
                    else{
                        gameOver = true;
                    }
                }
            }

            // Circles logic: big Circles
            for (int i = 0; i < MAX_CIRCLES; i++)
            {
                if (bigCircle[i].radius==0) bigCircle[i].active=true;
                bigCircle[i].radius+=2;
                if (bigCircle[i].radius>=100*MAX_CIRCLES)
                {
                    int r = GetRandomValue(0, 2);
                    int posx = GetRandomValue(0, 360);
                    int posy = posx+325-10*r;

                    bigCircle[i].position = (Vector2){screenWidth/2, screenHeight/2};
                    bigCircle[i].angle = (Vector2){posx, posy};

                    bigCircle[i].radius = 0;

                }
            }
        }
        if (IsKeyPressed('P')) printf("%d\n%d\n%d\n",(int)bigCircle[0].angle.x,(int)bigCircle[0].angle.y,(int)player.rotation);

    }
    else
    {
        if (IsKeyPressed(KEY_ENTER))
        {
            InitGame();
            gameOver = false;
        }
    }
}

// Draw game (one frame)
void DrawGame(void)
{
    BeginDrawing();

        ClearBackground(RAYWHITE);

        char str[28];
        char StrScore[20];
        sprintf(StrScore, "%d", score);
        strcpy(str, "SCORE : ");
        strcat(str, StrScore);

        char str2[28];
        char StrScore2[20];
        sprintf(StrScore2, "%d", highScore);
        strcpy(str2, "HIGHSCORE : ");
        strcat(str2, StrScore2);
        
        if (!gameOver)
        {
            DrawText(str, 20, 20, 20, GRAY);
            DrawText(str2, 20, 50, 20, DARKGRAY);

            // Draw Circles
            for (int i = 0; i < MAX_CIRCLES; i++)
            {
                if (bigCircle[i].active) {
                    DrawCircleSector(bigCircle[i].position, bigCircle[i].radius, bigCircle[i].angle.x, bigCircle[i].angle.y, 0, Fade(DARKGRAY, 0.3f));
                }
            }

            // Draw spaceship
            Vector2 v1 = { player.position.x + sinf(player.rotation*DEG2RAD)*(shipHeight), player.position.y - cosf(player.rotation*DEG2RAD)*(shipHeight) };
            Vector2 v2 = { player.position.x - cosf(player.rotation*DEG2RAD)*(PLAYER_BASE_SIZE/2), player.position.y - sinf(player.rotation*DEG2RAD)*(PLAYER_BASE_SIZE/2) };
            Vector2 v3 = { player.position.x + cosf(player.rotation*DEG2RAD)*(PLAYER_BASE_SIZE/2), player.position.y + sinf(player.rotation*DEG2RAD)*(PLAYER_BASE_SIZE/2) };
            DrawTriangle(v1, v2, v3, MAROON);


            if (pause) DrawText("GAME PAUSED", screenWidth/2 - MeasureText("GAME PAUSED", 40)/2, screenHeight/2 - 40, 40, GRAY);
        }
        else {
            DrawText(str2, GetScreenWidth()/2 - MeasureText("HIGHSCORE : 10", 20)/2, GetScreenHeight()/2 - 110, 20, DARKGRAY);
            DrawText(str, GetScreenWidth()/2 - MeasureText("SCORE : 10", 20)/2, GetScreenHeight()/2 - 80, 20, GRAY);
            DrawText("PRESS [ENTER] TO PLAY AGAIN", GetScreenWidth()/2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20)/2, GetScreenHeight()/2 - 50, 20, GRAY);
        }

    EndDrawing();
}

// Unload game variables
void UnloadGame(void)
{
    // TODO: Unload all dynamic loaded data (textures, sounds, models...)
}

// Update and Draw (one frame)
void UpdateDrawFrame(void)
{
    UpdateGame();
    DrawGame();
}