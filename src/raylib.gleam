pub type Color {
  Color(r: Int, g: Int, b: Int, a: Int)
}

pub const white = Color(255, 255, 255, 255)
pub const black = Color(0, 0, 0, 255)
pub const red = Color(255, 0, 0, 255)
pub const raywhite = Color(245, 245, 245, 255)

@external(erlang, "raylib_nif", "init_window")
pub fn init_window(width: Int, height: Int, title: String) -> Nil

@external(erlang, "raylib_nif", "set_target_fps")
pub fn set_target_fps(fps: Int) -> Nil

@external(erlang, "raylib_nif", "window_should_close")
pub fn window_should_close() -> Bool

@external(erlang, "raylib_nif", "begin_drawing")
pub fn begin_drawing() -> Nil

@external(erlang, "raylib_nif", "end_drawing")
pub fn end_drawing() -> Nil

@external(erlang, "raylib_nif", "close_window")
pub fn close_window() -> Nil

pub fn clear_background(color: Color) -> Nil {
  do_clear_background(color.r, color.g, color.b, color.a)
}

@external(erlang, "raylib_nif", "clear_background")
fn do_clear_background(r: Int, g: Int, b: Int, a: Int) -> Nil

pub fn draw_rectangle(x: Int, y: Int, width: Int, height: Int, color: Color) -> Nil {
  do_draw_rectangle(x, y, width, height, color.r, color.g, color.b, color.a)
}

@external(erlang, "raylib_nif", "draw_rectangle")
fn do_draw_rectangle(
  x: Int,
  y: Int,
  width: Int,
  height: Int,
  r: Int,
  g: Int,
  b: Int,
  a: Int,
) -> Nil
