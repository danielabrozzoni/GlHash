//
// Created by Alekos Filini on 17/08/2017.
//

#include "glhash.h"

float mapBitsToFloat(unsigned char byte, size_t nbits, size_t offset, float min, float max) {
    byte = byte >> offset;

    auto max_nbits = (1 << nbits) - 1;

    byte &= max_nbits;

    float range = max - min;
    auto percentage = static_cast<float>(1.0 * byte / max_nbits);

    return percentage * range + min;
}

GLfloat *getCoordinates(BYTE *input) {
    float offset[] =
        {
                0.0101f, 0.4541f, -0.3894f,
                -0.2547f, -0.1742f, -0.3743f,
                -0.4660f, 0.2561f, 0.0105f,
                -0.3039f, -0.1528f, -0.0177f,
                -0.1257f, -0.2521f, -0.1249f,
                -0.3035f, 0.2893f, -0.2638f,
                -0.1875f, -0.4132f, 0.1115f,
                -0.1614f, -0.0265f, -0.0168f,
                -0.4602f, 0.2115f, 0.2407f,
                0.4318f, -0.4798f, 0.2249f,
                -0.3431f, -0.1764f, -0.2437f,
                -0.1625f, 0.0632f, 0.3661f,
                -0.4569f, 0.3876f, 0.4523f,
                0.1702f, 0.0203f, -0.2327f,
                0.0343f, -0.2856f, -0.2317f,
                -0.1187f, -0.4633f, -0.0339f,
                -0.4471f, -0.1404f, -0.2422f,
                -0.0364f, -0.4190f, 0.0742f,
                -0.1658f, 0.4995f, -0.1877f,
                0.4410f, -0.1594f, 0.1974f,
                0.4545f, 0.1433f, -0.1176f,
                -0.2662f, 0.3605f, 0.0718f,
                -0.2377f, -0.4657f, 0.1920f,
                0.0765f, 0.1138f, -0.0782f,
                -0.1708f, 0.2269f, 0.3228f,
                0.0217f, -0.3370f, -0.4036f,
                -0.1486f, -0.1766f, 0.0068f,
                -0.0790f, 0.3372f, -0.4350f,
                -0.3778f, 0.3494f, 0.0870f,
                0.1980f, 0.1027f, 0.0786f,
                -0.1767f, -0.4938f, -0.2148f,
                -0.2309f, 0.0093f, 0.2271f,
                0.1256f, -0.2383f, -0.4313f,
                -0.1892f, -0.0079f, 0.0251f,
                0.3848f, -0.2827f, 0.0438f,
                0.2453f, -0.2592f, -0.3903f,
                0.1528f, -0.3434f, -0.4979f,
                -0.0222f, -0.4357f, -0.2045f,
                -0.2130f, -0.0971f, 0.2450f,
                0.1181f, 0.2489f, -0.0342f,
                -0.0874f, 0.3057f, 0.3057f,
                0.1334f, -0.0125f, 0.1538f,
                -0.4484f, 0.1361f, 0.3264f,
                -0.1403f, -0.2284f, 0.2623f,
                -0.1242f, 0.4559f, -0.0728f,
                -0.0777f, 0.2216f, 0.4552f,
                0.2450f, 0.1107f, 0.3623f,
                0.0590f, 0.1181f, -0.3118f,
                -0.3984f, -0.2403f, -0.3718f,
                0.0982f, 0.2638f, 0.1655f,
                0.1222f, 0.2314f, -0.4396f,
                0.1741f, -0.1974f, 0.2471f,
                -0.0474f, 0.0585f, 0.4167f,
                0.2001f, -0.4806f, -0.1857f,
                -0.2808f, 0.1091f, -0.2354f,
                -0.2932f, 0.2890f, 0.2738f,
                0.0681f, -0.3080f, -0.1278f,
                0.1418f, 0.3283f, -0.3165f,
                0.3555f, 0.2174f, 0.2561f,
                0.3552f, 0.0623f, 0.3043f,
                -0.4672f, -0.2316f, -0.2563f,
                -0.2263f, 0.4926f, 0.1584f,
                -0.2332f, 0.4194f, 0.0316f,
                0.0292f, 0.3603f, 0.2926f,
                -0.4475f, 0.3753f, -0.2076f,
                0.1744f, -0.1464f, 0.4112f,
                0.0303f, -0.2831f, -0.1951f,
                0.2397f, 0.2675f, 0.2553f,
                0.2456f, -0.0482f, -0.1793f,
                -0.1825f, -0.1072f, 0.3559f,
                0.0161f, -0.4856f, 0.2545f,
                -0.3087f, -0.3315f, -0.0121f,
                0.3901f, 0.3485f, -0.4535f,
                0.2397f, -0.2998f, -0.0978f,
                -0.3708f, 0.2291f, -0.0504f,
                0.3175f, -0.0918f, 0.4388f,
                0.4307f, 0.1905f, -0.1318f,
                0.2083f, -0.0174f, -0.3932f,
                -0.1549f, -0.4517f, -0.3494f,
                0.4567f, -0.2907f, 0.3569f,
                0.4173f, 0.3155f, 0.2765f,
                0.0693f, 0.3277f, -0.0485f,
                -0.4369f, -0.0090f, 0.1824f,
                -0.3573f, 0.1600f, 0.2682f,
                -0.3699f, -0.3592f, 0.3259f,
                -0.3249f, 0.3722f, -0.3797f,
                0.0814f, 0.3803f, -0.3541f,
                0.4629f, 0.2862f, 0.2307f,
                0.0519f, 0.4643f, 0.4849f,
                -0.4715f, -0.3548f, -0.3707f,
                0.2187f, -0.2176f, 0.0862f,
                -0.0956f, 0.2309f, -0.1405f,
                0.1407f, -0.1498f, -0.4463f,
                -0.2987f, 0.2466f, -0.3005f,
                0.2861f, 0.4493f, -0.3648f,
                -0.3384f, 0.0326f, 0.2135f,
                0.2095f, -0.3957f, 0.4588f,
                0.3630f, -0.1155f, 0.4994f,
                0.2175f, 0.2268f, -0.0590f

        };

    const size_t valuesCount = 3 * 3 * 11;
    size_t valuesRead = 0;

    auto *g_vertex_buffer_data = (GLfloat *) malloc(sizeof(GLfloat) * valuesCount);

    for (size_t i = 1; valuesRead < valuesCount; valuesRead += 4, i++) {
        g_vertex_buffer_data[valuesRead] = mapBitsToFloat(input[i], 2, 6, -1.0f, 1.0f) + offset[valuesRead];
        g_vertex_buffer_data[valuesRead + 1] = mapBitsToFloat(input[i], 2, 4, -1.0f, 1.0f) + offset[valuesRead + 1];
        g_vertex_buffer_data[valuesRead + 2] = mapBitsToFloat(input[i], 2, 2, -1.0f, 1.0f) - offset[valuesRead + 2];

        if (valuesRead < valuesCount) {
            g_vertex_buffer_data[valuesRead + 3] = mapBitsToFloat(input[i], 2, 0, -1.0f, 1.0f) - offset[valuesRead + 3];
        }
    }

    return g_vertex_buffer_data;
}

const float *getBackgroundColor(unsigned char byte) {
    static const float colors[][3] = {
            {0.0710f, 0.9740f, 0.3539f},
            {0.1140f, 0.9934f, 0.3332f},
            {0.7693f, 0.1634f, 0.8387f},
            {0.3534f, 0.1080f, 0.3241f},
            {0.5942f, 0.4349f, 0.0126f},
            {0.1975f, 0.6066f, 0.8348f},
            {0.9886f, 0.6968f, 0.1926f},
            {0.6739f, 0.7207f, 0.1276f},
            {0.2992f, 0.0065f, 0.8094f},
            {0.2020f, 0.2009f, 0.1535f},
            {0.1268f, 0.6308f, 0.4685f},
            {0.6876f, 0.6353f, 0.3025f},
            {0.2207f, 0.3062f, 0.9009f},
            {0.9661f, 0.6031f, 0.1793f},
            {0.8035f, 0.8235f, 0.8971f},
            {0.9318f, 0.1018f, 0.5173f},
            {0.4618f, 0.1842f, 0.3227f},
            {0.3325f, 0.4307f, 0.3257f},
            {0.3156f, 0.5118f, 0.5193f},
            {0.1113f, 0.0788f, 0.4710f},
            {0.8032f, 0.2406f, 0.2686f},
            {0.0921f, 0.2453f, 0.9127f},
            {0.8258f, 0.3478f, 0.0149f},
            {0.8814f, 0.9437f, 0.8387f},
            {0.0653f, 0.9271f, 0.7485f},
            {0.6910f, 0.3329f, 0.7138f},
            {0.8558f, 0.6657f, 0.6951f},
            {0.4690f, 0.9421f, 0.4169f},
            {0.7882f, 0.5498f, 0.6903f},
            {0.8299f, 0.8481f, 0.8765f},
            {0.7491f, 0.7002f, 0.2828f},
            {0.1007f, 0.6435f, 0.7940f},
            {0.9658f, 0.8211f, 0.9393f},
            {0.3110f, 0.7473f, 0.1176f},
            {0.7174f, 0.7123f, 0.2547f},
            {0.0133f, 0.4267f, 0.5970f},
            {0.4554f, 0.4611f, 0.1713f},
            {0.4088f, 0.6631f, 0.1809f},
            {0.0802f, 0.0077f, 0.8875f},
            {0.2177f, 0.1443f, 0.0050f},
            {0.1432f, 0.0856f, 0.9652f},
            {0.1716f, 0.4940f, 0.0846f},
            {0.2801f, 0.5948f, 0.0123f},
            {0.1504f, 0.7288f, 0.6765f},
            {0.8318f, 0.5993f, 0.8905f},
            {0.8530f, 0.6866f, 0.2452f},
            {0.7487f, 0.5274f, 0.4530f},
            {0.3996f, 0.5042f, 0.7091f},
            {0.6005f, 0.8473f, 0.1931f},
            {0.2614f, 0.6375f, 0.9035f},
            {0.9967f, 0.7936f, 0.7665f},
            {0.9721f, 0.0019f, 0.7511f},
            {0.3206f, 0.4151f, 0.2178f},
            {0.6517f, 0.4382f, 0.8908f},
            {0.8438f, 0.8919f, 0.6887f},
            {0.6202f, 0.6231f, 0.8582f},
            {0.0869f, 0.3559f, 0.5673f},
            {0.9832f, 0.4738f, 0.6782f},
            {0.6591f, 0.8483f, 0.5591f},
            {0.3979f, 0.0253f, 0.6909f},
            {0.3629f, 0.9276f, 0.3089f},
            {0.1403f, 0.7908f, 0.5032f},
            {0.3401f, 0.9814f, 0.0180f},
            {0.5644f, 0.8534f, 0.3455f},
            {0.5633f, 0.3003f, 0.6428f},
            {0.6901f, 0.4441f, 0.0719f},
            {0.0433f, 0.2907f, 0.1103f},
            {0.8791f, 0.2696f, 0.2173f},
            {0.5227f, 0.2301f, 0.7036f},
            {0.0063f, 0.4379f, 0.6584f},
            {0.6746f, 0.6471f, 0.8518f},
            {0.8906f, 0.9195f, 0.1515f},
            {0.2328f, 0.5765f, 0.2710f},
            {0.5709f, 0.5777f, 0.9788f},
            {0.2344f, 0.2577f, 0.1528f},
            {0.6473f, 0.2833f, 0.7589f},
            {0.7306f, 0.5680f, 0.7051f},
            {0.1138f, 0.2744f, 0.8975f},
            {0.8920f, 0.3004f, 0.4915f},
            {0.9304f, 0.9768f, 0.6689f},
            {0.5964f, 0.5291f, 0.6342f},
            {0.8680f, 0.4343f, 0.4484f},
            {0.9366f, 0.3696f, 0.0914f},
            {0.0760f, 0.9122f, 0.8729f},
            {0.5381f, 0.3094f, 0.8791f},
            {0.3911f, 0.1481f, 0.7969f},
            {0.5225f, 0.6756f, 0.9616f},
            {0.5873f, 0.8542f, 0.7655f},
            {0.1681f, 0.3330f, 0.3065f},
            {0.2976f, 0.4718f, 0.0976f},
            {0.1311f, 0.2645f, 0.8471f},
            {0.8516f, 0.2967f, 0.4519f},
            {0.0331f, 0.4967f, 0.5530f},
            {0.2119f, 0.6418f, 0.2413f},
            {0.3523f, 0.9429f, 0.8182f},
            {0.4431f, 0.5031f, 0.5056f},
            {0.6685f, 0.0735f, 0.7743f},
            {0.1795f, 0.3752f, 0.4500f},
            {0.9413f, 0.0043f, 0.2919f},
            {0.6607f, 0.8140f, 0.7144f},
            {0.8615f, 0.6582f, 0.8099f},
            {0.2395f, 0.6173f, 0.0730f},
            {0.6645f, 0.2717f, 0.2246f},
            {0.6141f, 0.6438f, 0.1603f},
            {0.6735f, 0.9231f, 0.6113f},
            {0.2650f, 0.7239f, 0.1854f},
            {0.2070f, 0.4646f, 0.3174f},
            {0.4929f, 0.8482f, 0.7528f},
            {0.1039f, 0.0191f, 0.2953f},
            {0.2256f, 0.8497f, 0.5639f},
            {0.9630f, 0.2783f, 0.8827f},
            {0.8163f, 0.5574f, 0.1672f},
            {0.3612f, 0.0970f, 0.5536f},
            {0.1016f, 0.7947f, 0.0855f},
            {0.3736f, 0.0836f, 0.8535f},
            {0.0403f, 0.8479f, 0.5534f},
            {0.7106f, 0.3007f, 0.2862f},
            {0.6971f, 0.4777f, 0.5168f},
            {0.4215f, 0.0530f, 0.1696f},
            {0.4329f, 0.4865f, 0.3625f},
            {0.6437f, 0.4102f, 0.3273f},
            {0.5862f, 0.2348f, 0.0860f},
            {0.8405f, 0.1115f, 0.8061f},
            {0.6761f, 0.1741f, 0.9089f},
            {0.2312f, 0.1080f, 0.1117f},
            {0.7492f, 0.0763f, 0.8057f},
            {0.0161f, 0.7641f, 0.4414f},
            {0.1852f, 0.1270f, 0.7010f},
            {0.6869f, 0.0361f, 0.9191f},
            {0.1637f, 0.2330f, 0.4880f},
            {0.6007f, 0.0848f, 0.2211f},
            {0.4682f, 0.6992f, 0.6636f},
            {0.8492f, 0.1354f, 0.6764f},
            {0.0085f, 0.4856f, 0.9439f},
            {0.4490f, 0.4812f, 0.6368f},
            {0.9511f, 0.5671f, 0.8148f},
            {0.5804f, 0.8210f, 0.4339f},
            {0.3450f, 0.1039f, 0.6584f},
            {0.4070f, 0.1519f, 0.4183f},
            {0.7921f, 0.3349f, 0.3774f},
            {0.5833f, 0.5470f, 0.7027f},
            {0.9767f, 0.2267f, 0.6487f},
            {0.6940f, 0.7488f, 0.2727f},
            {0.8628f, 0.2769f, 0.0699f},
            {0.6080f, 0.4330f, 0.4537f},
            {0.5219f, 0.3934f, 0.7303f},
            {0.1754f, 0.3362f, 0.0667f},
            {0.2227f, 0.5908f, 0.7273f},
            {0.4309f, 0.2585f, 0.0034f},
            {0.7403f, 0.3889f, 0.8055f},
            {0.1759f, 0.1209f, 0.7429f},
            {0.3038f, 0.2330f, 0.6303f},
            {0.0981f, 0.3018f, 0.6504f},
            {0.2340f, 0.6084f, 0.1541f},
            {0.9818f, 0.4674f, 0.8468f},
            {0.4999f, 0.5212f, 0.1037f},
            {0.3652f, 0.1531f, 0.7716f},
            {0.2546f, 0.6100f, 0.2007f},
            {0.6503f, 0.4538f, 0.5852f},
            {0.0454f, 0.4013f, 0.3206f},
            {0.6762f, 0.2383f, 0.7456f},
            {0.4810f, 0.4910f, 0.4530f},
            {0.9375f, 0.0654f, 0.7440f},
            {0.0058f, 0.0173f, 0.8064f},
            {0.9941f, 0.4200f, 0.9884f},
            {0.8403f, 0.8697f, 0.6298f},
            {0.1475f, 0.0560f, 0.8877f},
            {0.7418f, 0.7054f, 0.8130f},
            {0.0611f, 0.7185f, 0.7017f},
            {0.9826f, 0.4781f, 0.1728f},
            {0.4247f, 0.8702f, 0.1839f},
            {0.0604f, 0.5615f, 0.3075f},
            {0.7330f, 0.1015f, 0.2880f},
            {0.0290f, 0.0421f, 0.0507f},
            {0.6881f, 0.5085f, 0.9229f},
            {0.1861f, 0.1732f, 0.3205f},
            {0.8821f, 0.8553f, 0.9069f},
            {0.2120f, 0.1337f, 0.4861f},
            {0.6443f, 0.7491f, 0.2579f},
            {0.0616f, 0.4265f, 0.2720f},
            {0.0810f, 0.2275f, 0.4792f},
            {0.9504f, 0.0125f, 0.1915f},
            {0.4007f, 0.6670f, 0.1673f},
            {0.0517f, 0.8485f, 0.0547f},
            {0.1891f, 0.7553f, 0.0113f},
            {0.6773f, 0.1974f, 0.5578f},
            {0.6759f, 0.6464f, 0.5743f},
            {0.3999f, 0.3211f, 0.9784f},
            {0.0753f, 0.7614f, 0.7228f},
            {0.9891f, 0.3058f, 0.3180f},
            {0.6924f, 0.4076f, 0.9831f},
            {0.0100f, 0.1784f, 0.5787f},
            {0.7891f, 0.2237f, 0.0396f},
            {0.0681f, 0.3427f, 0.7627f},
            {0.3413f, 0.7248f, 0.9204f},
            {0.0975f, 0.0835f, 0.2738f},
            {0.0575f, 0.5437f, 0.6763f},
            {0.7628f, 0.7596f, 0.6515f},
            {0.0252f, 0.9973f, 0.4041f},
            {0.3042f, 0.1139f, 0.4591f},
            {0.3693f, 0.9392f, 0.0215f},
            {0.6150f, 0.7322f, 0.3446f},
            {0.4045f, 0.9146f, 0.1508f},
            {0.1456f, 0.1931f, 0.8691f},
            {0.3819f, 0.4477f, 0.3342f},
            {0.8365f, 0.7111f, 0.8476f},
            {0.9777f, 0.6953f, 0.2437f},
            {0.0050f, 0.2113f, 0.4883f},
            {0.0797f, 0.3437f, 0.6857f},
            {0.4534f, 0.8503f, 0.4923f},
            {0.6135f, 0.7907f, 0.4891f},
            {0.9500f, 0.9643f, 0.6627f},
            {0.2895f, 0.8586f, 0.0188f},
            {0.4445f, 0.3820f, 0.1222f},
            {0.6698f, 0.7406f, 0.8250f},
            {0.9306f, 0.3502f, 0.9531f},
            {0.6991f, 0.1657f, 0.2108f},
            {0.3061f, 0.8957f, 0.1087f},
            {0.5621f, 0.4554f, 0.7235f},
            {0.2586f, 0.5494f, 0.4224f},
            {0.5064f, 0.2496f, 0.2785f},
            {0.8613f, 0.4453f, 0.0474f},
            {0.2838f, 0.7344f, 0.1027f},
            {0.0464f, 0.4197f, 0.9647f},
            {0.6350f, 0.6962f, 0.1139f},
            {0.6671f, 0.1968f, 0.9916f},
            {0.5945f, 0.3498f, 0.8834f},
            {0.3812f, 0.7740f, 0.5341f},
            {0.9676f, 0.8418f, 0.8314f},
            {0.0777f, 0.1748f, 0.0289f},
            {0.3460f, 0.9942f, 0.5351f},
            {0.5889f, 0.0929f, 0.1508f},
            {0.5992f, 0.5453f, 0.5096f},
            {0.4416f, 0.1862f, 0.3799f},
            {0.9995f, 0.2313f, 0.5969f},
            {0.1174f, 0.6890f, 0.8491f},
            {0.5878f, 0.8010f, 0.5301f},
            {0.1427f, 0.2001f, 0.9710f},
            {0.6076f, 0.2971f, 0.9628f},
            {0.8302f, 0.6975f, 0.8901f},
            {0.5232f, 0.6092f, 0.6104f},
            {0.7863f, 0.6537f, 0.1041f},
            {0.8818f, 0.8276f, 0.7090f},
            {0.5987f, 0.8344f, 0.0439f},
            {0.9356f, 0.8215f, 0.7070f},
            {0.5407f, 0.6926f, 0.3961f},
            {0.3711f, 0.0656f, 0.7569f},
            {0.4517f, 0.1466f, 0.4409f},
            {0.0317f, 0.2425f, 0.7789f},
            {0.0698f, 0.1035f, 0.0710f},
            {0.7740f, 0.8232f, 0.7080f},
            {0.6262f, 0.6544f, 0.8561f},
            {0.6513f, 0.6901f, 0.7096f},
            {0.6026f, 0.9868f, 0.9234f},
            {0.6510f, 0.7487f, 0.4828f},
            {0.5406f, 0.1968f, 0.7643f}
    };

    return (float *) colors[byte];
}