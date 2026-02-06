#include <string.h>

#include "erl_nif.h"
#include "raylib.h"

static ERL_NIF_TERM nif_init_window(ErlNifEnv* env, int argc,
                                    const ERL_NIF_TERM argv[]) {
    int width, height;
    ErlNifBinary title_bin;

    if (!enif_get_int(env, argv[0], &width) ||
        !enif_get_int(env, argv[1], &height) ||
        !enif_inspect_binary(env, argv[2], &title_bin)) {
        return enif_make_badarg(env);
    }

    char title[256];
    size_t len = title_bin.size < 255 ? title_bin.size : 255;
    memcpy(title, title_bin.data, len);
    title[len] = '\0';

    InitWindow(width, height, title);
    return enif_make_atom(env, "nil");
}

static ERL_NIF_TERM nif_set_target_fps(ErlNifEnv* env, int argc,
                                       const ERL_NIF_TERM argv[]) {
    int fps;

    if (!enif_get_int(env, argv[0], &fps)) {
        return enif_make_badarg(env);
    }

    SetTargetFPS(fps);
    return enif_make_atom(env, "nil");
}

static ERL_NIF_TERM nif_window_should_close(ErlNifEnv* env, int argc,
                                            const ERL_NIF_TERM argv[]) {
    bool should_close = WindowShouldClose();
    return enif_make_atom(env, should_close ? "true" : "false");
}

static ERL_NIF_TERM nif_begin_drawing(ErlNifEnv* env, int argc,
                                      const ERL_NIF_TERM argv[]) {
    BeginDrawing();
    return enif_make_atom(env, "nil");
}

static ERL_NIF_TERM nif_end_drawing(ErlNifEnv* env, int argc,
                                    const ERL_NIF_TERM argv[]) {
    EndDrawing();
    return enif_make_atom(env, "nil");
}

static ERL_NIF_TERM nif_clear_background(ErlNifEnv* env, int argc,
                                         const ERL_NIF_TERM argv[]) {
    int r, g, b, a;

    if (!enif_get_int(env, argv[0], &r) || !enif_get_int(env, argv[1], &g) ||
        !enif_get_int(env, argv[2], &b) || !enif_get_int(env, argv[3], &a)) {
        return enif_make_badarg(env);
    }

    Color color = {r, g, b, a};
    ClearBackground(color);
    return enif_make_atom(env, "nil");
}

static ERL_NIF_TERM nif_draw_rectangle(ErlNifEnv* env, int argc,
                                       const ERL_NIF_TERM argv[]) {
    int x, y, width, height, r, g, b, a;

    if (!enif_get_int(env, argv[0], &x) || !enif_get_int(env, argv[1], &y) ||
        !enif_get_int(env, argv[2], &width) ||
        !enif_get_int(env, argv[3], &height) ||
        !enif_get_int(env, argv[4], &r) || !enif_get_int(env, argv[5], &g) ||
        !enif_get_int(env, argv[6], &b) || !enif_get_int(env, argv[7], &a)) {
        return enif_make_badarg(env);
    }

    Color color = {r, g, b, a};
    DrawRectangle(x, y, width, height, color);
    return enif_make_atom(env, "nil");
}

static ERL_NIF_TERM nif_close_window(ErlNifEnv* env, int argc,
                                     const ERL_NIF_TERM argv[]) {
    CloseWindow();
    return enif_make_atom(env, "nil");
}

static ErlNifFunc nif_funcs[] = {
    {"init_window", 3, nif_init_window},
    {"set_target_fps", 1, nif_set_target_fps},
    {"window_should_close", 0, nif_window_should_close},
    {"begin_drawing", 0, nif_begin_drawing},
    {"end_drawing", 0, nif_end_drawing},
    {"clear_background", 4, nif_clear_background},
    {"draw_rectangle", 8, nif_draw_rectangle},
    {"close_window", 0, nif_close_window}};

ERL_NIF_INIT(raylib_nif, nif_funcs, NULL, NULL, NULL, NULL)
