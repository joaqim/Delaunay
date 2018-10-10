#version 330 core

in vec4 position;
   
out vec4 color;

layout (std140) uniform Matrices {
    mat4 pvm;
};

float PHI = 1.61803398874989484820459 * 00000.1; // Golden Ratio   
float PI  = 3.14159265358979323846264 * 00000.1; // PI
float SQ2 = 1.41421356237309504880169 * 10000.0; // Square Root of Two

float gold_noise(in vec2 coordinate, in float seed){
    return fract(tan(distance(coordinate*(seed+PHI), vec2(PHI, PI)))*SQ2);
}

// Generate a random float in the range [0.0f, 1.0f] using x, y, and z (based on the xor128 algorithm)
float rand(int x, int y, int z)
{
    int seed = x + y * 57 + z * 241;
    seed= (seed<< 13) ^ seed;
    return (( 1.0 - ( (seed * (seed * seed * 15731 + 789221) + 1376312589) & 2147483647) / 1073741824.0f) + 1.0f) / 2.0f;
}

float smoothVoronoi( in vec2 x )
{
    ivec2 p = ivec2(floor( x ));
    vec2  f = fract( x );

    float res = 0.0;
    for( int j=-1; j<=1; j++ )
    for( int i=-1; i<=1; i++ )
    {
        ivec2 b = ivec2( i, j );
        vec2  r = vec2( b ) - f + gold_noise( p + b , rand(i,j,int(f)));
        float d = dot( r, r );

        res += 1.0/pow( d, 8.0 );
    }
    return pow( 1.0/res, 1.0/16.0 );
}

void main() {
     gl_Position = position;
     gl_PointSize = 10.0;

//color = position;
// gl_Position = pvm * position ;

float pct = smoothVoronoi(vec2(gl_Position));
vec3 color3 = pct*vec3(0.0,1.0,0.0);
color = vec4(color3,1.0);

}
