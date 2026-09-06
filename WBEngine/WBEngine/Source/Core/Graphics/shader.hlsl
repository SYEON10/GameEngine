cbuffer MVP_MATRIX : register(b0)
{
    row_major matrix World;
    row_major matrix View;
    row_major matrix Projection;
};

struct VS_OUTPUT
{
    float4 Pos : SV_POSITION;
    float4 Color : COLOR;
};

VS_OUTPUT VShader(float4 pos : POSITION, float4 color : COLOR)
{
    VS_OUTPUT output;
    
    float4 worldPos = mul(World, pos);
    float4 viewPos = mul(View, worldPos);
    float4 projPos = mul(Projection, viewPos);
    output.Pos = projPos;
    
    output.Color = color;
    
    return output;
}

float4 PShader(VS_OUTPUT input) : SV_TARGET
{
    return input.Color;
}