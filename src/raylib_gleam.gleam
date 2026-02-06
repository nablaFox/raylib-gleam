import raylib
import gleam/io

pub fn main() {
  raylib.init_window(800, 600, "Gleam + Raylib - Red Square")
  raylib.set_target_fps(60)

  game_loop()

  raylib.close_window()
  io.println("Window closed!")
}

fn game_loop() {
  case raylib.window_should_close() {
    True -> Nil
    False -> {
      raylib.begin_drawing()
      
      raylib.clear_background(raylib.raywhite)
      
      raylib.draw_rectangle(350, 250, 100, 100, raylib.red)
      
      raylib.end_drawing()
      
      game_loop()
    }
  }
}
