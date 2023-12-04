#ifndef RENDERER_HPP
#define RENDERER_HPP

class Renderer {
    public:
        virtual ~Renderer() = default;
        virtual void execute() = 0;
};

#endif // RENDERER_HPP