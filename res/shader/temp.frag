uniform vec3 CoolestColor;
uniform vec3 HottestColor;
varying float Temperature;

void main()
{
    Vec3 color = mix(CoolestColor,HottestColor,Temperature);
    gl_FragColor = vec4(color,1.0);
}
