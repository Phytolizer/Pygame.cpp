#pragma once

class GraphicsContext
{
  public:
    GraphicsContext();
    GraphicsContext(const GraphicsContext&) = delete;
    GraphicsContext& operator=(const GraphicsContext&) = delete;
    GraphicsContext(GraphicsContext&&) = delete;
    GraphicsContext& operator=(GraphicsContext&&) = delete;
    ~GraphicsContext();
};
