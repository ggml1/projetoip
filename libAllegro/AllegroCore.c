#include "AllegroCore.h"

bool coreInit()
{
    //modules and add-ons initialization
	if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar Allegro.\n");
        return false;
    }

    if (!al_init_image_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_image.\n");
        return false;
    }

    if (!al_init_font_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_font.\n");
        return false;
    }

    if (!al_init_ttf_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_ttf.\n");
        return false;
    }

    if (!al_init_primitives_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_primitives.\n");
        return false;
    }


    eventsQueue = al_create_event_queue();
    if (!eventsQueue)
    {
        fprintf(stderr, "Falha ao criar fila de eventos.\n");
        return false;
    }

 	

    return true;
}

bool windowInit(int W, int H, char title[])
{
    main_window = al_create_display(W, H);
    if (!main_window)
    {
        fprintf(stderr, "Falha ao criar janela.\n");
        return false;
    }
    al_set_window_title(main_window, title);

    al_register_event_source(eventsQueue, al_get_display_event_source(main_window));

    return true;
}

bool inputInit()
{
	/*------------------------------MOUSE--------------------------------*/
	//Inicializa Mouse
	if (!al_install_mouse())
    {
        fprintf(stderr, "Falha ao inicializar o mouse.\n");
        al_destroy_display(main_window);
        return false;
    }

    // Atribui o cursor padrão do sistema para ser usado
    if (!al_set_system_mouse_cursor(main_window, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT))
    {
        fprintf(stderr, "Falha ao atribuir ponteiro do mouse.\n");
        al_destroy_display(main_window);
        return false;
    }
    /*------------------------------MOUSE--------------------------------*/

    /*------------------------------TECLADO------------------------------*/
    if (!al_install_keyboard())
    {
        fprintf(stderr, "Falha ao inicializar o teclado.\n");
        return false;
    }

    /*------------------------------TECLADO------------------------------*/


    //Registra mouse e teclado na fila de eventos
    al_register_event_source(eventsQueue, al_get_mouse_event_source());
    al_register_event_source(eventsQueue, al_get_keyboard_event_source());

    return true;
}

bool fontInit()
{
    /*------------------------------FONTE--------------------------------*/
    font_1 = al_load_font("Resources/Fonts/Boxy-Bold.ttf", 45, 0);
    if (!font_1)
    {
        fprintf(stderr, "Falha ao carregar \"Boxy-Bold.ttf\".\n");
        return false;
    }
	font_2 = al_load_font("Resources/Fonts/Boxy-Bold.ttf", 25, 0);
    if (!font_2)
    {
        fprintf(stderr, "Falha ao carregar \"Boxy-Bold.ttf\".\n");
        return false;
    }
    font_3 = al_load_font("Resources/Fonts/Boxy-Bold.ttf", 120, 0);
    if (!font_3)
    {
        fprintf(stderr, "Falha ao carregar \"Boxy-Bold.ttf\".\n");
        return false;
    }

    return true;
}

void allegroEnd()
{
    al_destroy_display(main_window);
    al_destroy_event_queue(eventsQueue);
}

void startTimer()
{
    startingTime = al_get_time();
}

void startTimerBlink()
{
    startingTimeBlink = al_get_time();
}

double getTimer()
{
    return al_get_time() - startingTime;
}

double getTimerBlink()
{
    return al_get_time() - startingTimeBlink;
}

void FPSLimit()
{
	if (getTimer() < 1.0/FPS)
    {
        al_rest((1.0 / FPS) - getTimer());
    }
}

bool Blink(){
    if(getTimerBlink() < 1) return 0;
    else{
        startTimerBlink();
        return 1;
    }
}

bool loadGraphics() 
{
    tileSet = al_load_bitmap("Resources/Tilesets/tileset.png");
    if(!tileSet){
        fprintf(stderr, "Falha ao carregar o tileset.\n");
        return false;
    }

    menuOpcoes = al_load_bitmap("Resources/Etc/menuOpcoes.png");
    if(!menuOpcoes){
        fprintf(stderr, "Falha ao carregar o tileset.\n");
        return false;
    }

    menuInicio = al_load_bitmap("Resources/Etc/menuInicio.png");
    if(!menuInicio){
        fprintf(stderr, "Falha ao carregar o tileset.\n");
        return false;
    }

    menuNormal = al_load_bitmap("Resources/Etc/menuNormal.png");
    if(!menuNormal){
        fprintf(stderr, "Falha ao carregar o tileset.\n");
        return false;
    }

    seta = al_load_bitmap("Resources/Etc/seta.png");
    if(!seta){
        fprintf(stderr, "Falha ao carregar o seta.\n");
        return false;
    }

    upKey = al_load_bitmap("Resources/Etc/up.png");
    if(!upKey){
        fprintf(stderr, "Falha ao carregar a sprite UPKEY.\n");
        return false;
    }

    downKey = al_load_bitmap("Resources/Etc/down.png");
    if(!downKey){
        fprintf(stderr, "Falha ao carregar a sprite DOWNKEY.\n");
        return false;
    }

    rightKey = al_load_bitmap("Resources/Etc/right.png");
    if(!rightKey){
        fprintf(stderr, "Falha ao carregar a sprite RIGHTKEY.\n");
        return false;
    }

    leftKey = al_load_bitmap("Resources/Etc/left.png");
    if(!leftKey){
        fprintf(stderr, "Falha ao carregar a sprite LEFTKEY.\n");
        return false;
    }
    
    Dungeon_B = al_load_bitmap("Resources/Tilesets/Dungeon_B.png");
    if(!Dungeon_B){
        fprintf(stderr, "Falha ao carregar a Dungeon_B.\n");
        return false;
    }

    Outside_B = al_load_bitmap("Resources/Tilesets/Outside_B.png");
    if(!Outside_B){
        fprintf(stderr, "Falha ao carregar a Outside_B.\n");
        return false;
    }

    World_B = al_load_bitmap("Resources/Tilesets/World_B.png");
    if(!World_B){
        fprintf(stderr, "Falha ao carregar a World_B.\n");
        return false;
    }

    Dungeon_A2 = al_load_bitmap("Resources/Tilesets/Dungeon_A2.png");
    if(!Dungeon_A2){
        fprintf(stderr, "Falha ao carregar a Dungeon_A2.\n");
        return false;
    }

    Inside_C = al_load_bitmap("Resources/Tilesets/Inside_C.png");
    if(!Inside_C){
        fprintf(stderr, "Falha ao carregar a Inside_C.\n");
        return false;
    }

    Shadow = al_load_bitmap("Resources/Tilesets/Shadow.png");
    if(!Shadow){
        fprintf(stderr, "Falha ao carregar a Shadow.\n");
        return false;
    }

    TileC = al_load_bitmap("Resources/Tilesets/TileC.png");
    if(!TileC){
        fprintf(stderr, "Falha ao carregar a TileC.\n");
        return false;
    }

    red = al_load_bitmap("Resources/Tilesets/red.png");
    if(!red){
        fprintf(stderr, "Falha ao carregar a red.\n");
        return false;
    }

    blue = al_load_bitmap("Resources/Tilesets/blue.png");
    if(!blue){
        fprintf(stderr, "Falha ao carregar a blue.\n");
        return false;
    }

    heart_14 = al_load_bitmap("Resources/Etc/heart_14.png");
    if(!heart_14){
        fprintf(stderr, "Falha ao carregar a heart_14.\n");
        return false;
    }

    heart_24 = al_load_bitmap("Resources/Etc/heart_24.png");
    if(!heart_24){
        fprintf(stderr, "Falha ao carregar a heart_24.\n");
        return false;
    }

    heart_34 = al_load_bitmap("Resources/Etc/heart_34.png");
    if(!heart_34){
        fprintf(stderr, "Falha ao carregar a heart_34.\n");
        return false;
    }

    heart_44 = al_load_bitmap("Resources/Etc/heart_44.png");
    if(!heart_44){
        fprintf(stderr, "Falha ao carregar a heart_44.\n");
        return false;
    }

    spaceTecla = al_load_bitmap("Resources/Etc/space.png");
    if(!spaceTecla){
        fprintf(stderr, "Falha ao carregar a space.\n");
        return false;
    }

    telaMorte = al_load_bitmap("Resources/Etc/telaMorte.png");
    if(!telaMorte){
        fprintf(stderr, "Falha ao carregar a telaMorte.\n");
        return false;
    }

    bmagicr = al_load_bitmap("Resources/Attacks/blue_bullet_right.png");
    if(!bmagicr){
        fprintf(stderr, "Falha ao carregar a 1.\n");
        return false;
    }

    bmagicu = al_load_bitmap("Resources/Attacks/blue_bullet_up.png");
    if(!bmagicu){
        fprintf(stderr, "Falha ao carregar a 2.\n");
        return false;
    }

    bmagicl = al_load_bitmap("Resources/Attacks/blue_bullet_left.png");
    if(!bmagicl){
        fprintf(stderr, "Falha ao carregar a 3.\n");
        return false;
    }

    bmagicd = al_load_bitmap("Resources/Attacks/blue_bullet_down.png");
    if(!bmagicd){
        fprintf(stderr, "Falha ao carregar a 4.\n");
        return false;
    }

    rmagicr = al_load_bitmap("Resources/Attacks/red_bullet_right.png");
    if(!rmagicr){
        fprintf(stderr, "Falha ao carregar a 5.\n");
        return false;
    }

    rmagicd = al_load_bitmap("Resources/Attacks/red_bullet_down.png");
    if(!rmagicd){
        fprintf(stderr, "Falha ao carregar a 6.\n");
        return false;
    }

    rmagicl = al_load_bitmap("Resources/Attacks/red_bullet_left.png");
    if(!rmagicl){
        fprintf(stderr, "Falha ao carregar a 7.\n");
        return false;
    }

    rmagicu = al_load_bitmap("Resources/Attacks/red_bullet_up.png");
    if(!rmagicu){
        fprintf(stderr, "Falha ao carregar a 8.\n");
        return false;
    }

    bslashr = al_load_bitmap("Resources/Attacks/BLUE_espadada_right.png");
    if(!bslashr){
        fprintf(stderr, "Falha ao carregar a 9.\n");
        return false;
    }

    bslashu = al_load_bitmap("Resources/Attacks/BLUE_espadada_up.png");
    if(!bslashu){
        fprintf(stderr, "Falha ao carregar a 10.\n");
        return false;
    }

    bslashl = al_load_bitmap("Resources/Attacks/BLUE_espadada_left.png");
    if(!bslashl){
        fprintf(stderr, "Falha ao carregar a 11.\n");
        return false;
    }

    bslashd = al_load_bitmap("Resources/Attacks/BLUE_espadada_down.png");
    if(!bslashd){
        fprintf(stderr, "Falha ao carregar a 12.\n");
        return false;
    }

    rslashr = al_load_bitmap("Resources/Attacks/RED_espadada_right.png");
    if(!rslashr){
        fprintf(stderr, "Falha ao carregar a 13.\n");
        return false;
    }

    rslashu = al_load_bitmap("Resources/Attacks/RED_espadada_up.png");
    if(!rslashu){
        fprintf(stderr, "Falha ao carregar a 14.\n");
        return false;
    }  

    rslashd = al_load_bitmap("Resources/Attacks/RED_espadada_down.png");
    if(!rslashd){
        fprintf(stderr, "Falha ao carregar a 15.\n");
        return false;
    }

    rslashl = al_load_bitmap("Resources/Attacks/RED_espadada_left.png");
    if(!rslashl){
        fprintf(stderr, "Falha ao carregar a 16.\n");
        return false;
    }

    barrowr = al_load_bitmap("Resources/Attacks/BLUE_flecha32bits_right.png");
    if(!barrowr){
        fprintf(stderr, "Falha ao carregar a 17.\n");
        return false;
    }

    barrowd = al_load_bitmap("Resources/Attacks/BLUE_flecha32bits_down.png");
    if(!barrowd){
        fprintf(stderr, "Falha ao carregar a 18.\n");
        return false;
    }

    barrowl = al_load_bitmap("Resources/Attacks/BLUE_flecha32bits_left.png");
    if(!barrowl){
        fprintf(stderr, "Falha ao carregar a 19.\n");
        return false;
    }

    barrowu = al_load_bitmap("Resources/Attacks/BLUE_flecha32bits_up.png");
    if(!barrowu){
        fprintf(stderr, "Falha ao carregar a 20.\n");
        return false;
    }

    rarrowr = al_load_bitmap("Resources/Attacks/RED_flecha32bits_right.png");
    if(!rarrowr){
        fprintf(stderr, "Falha ao carregar a 21.\n");
        return false;
    }

    rarrowd = al_load_bitmap("Resources/Attacks/RED_flecha32bits_down.png");
    if(!rarrowd){
        fprintf(stderr, "Falha ao carregar a 22.\n");
        return false;
    }

    rarrowl = al_load_bitmap("Resources/Attacks/RED_flecha32bits_left.png");
    if(!rarrowl){
        fprintf(stderr, "Falha ao carregar a 23.\n");
        return false;
    }

    rarrowu = al_load_bitmap("Resources/Attacks/RED_flecha32bits_up.png");
    if(!rarrowu){
        fprintf(stderr, "Falha ao carregar a 24.\n");
        return false;

    }
    trofeu_tela = al_load_bitmap("Resources/Etc/trofeu_tela.png");
    if(!trofeu_tela){
        fprintf(stderr, "Falha ao carregar a tela de vitoria.\n");
        return false;

    }
    return true;
}
