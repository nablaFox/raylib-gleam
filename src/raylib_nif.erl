-module(raylib_nif).
-export([
    init_window/3,
    set_target_fps/1,
    window_should_close/0,
    begin_drawing/0,
    end_drawing/0,
    clear_background/4,
    draw_rectangle/8,
    close_window/0
]).
-nifs([
    init_window/3,
    set_target_fps/1,
    window_should_close/0,
    begin_drawing/0,
    end_drawing/0,
    clear_background/4,
    draw_rectangle/8,
    close_window/0
]).
-on_load(init/0).

init() ->
    erlang:load_nif("priv/libraylib_nif", 0).

init_window(_, _, _) -> erlang:nif_error(not_loaded).
set_target_fps(_) -> erlang:nif_error(not_loaded).
window_should_close() -> erlang:nif_error(not_loaded).
begin_drawing() -> erlang:nif_error(not_loaded).
end_drawing() -> erlang:nif_error(not_loaded).
clear_background(_, _, _, _) -> erlang:nif_error(not_loaded).
draw_rectangle(_, _, _, _, _, _, _, _) -> erlang:nif_error(not_loaded).
close_window() -> erlang:nif_error(not_loaded).
