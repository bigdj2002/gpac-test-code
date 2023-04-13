#include <iostream>
#include <gpac/isomedia.h>

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    std::cerr << "Usage: " << argv[0] << " <input_file.mp4>" << std::endl;
    return 1;
  }

  GF_ISOFile *file = gf_isom_open(argv[1], GF_ISOM_OPEN_READ, 0);
  if (!file)
  {
    return 1;
  }

  u32 track_count = gf_isom_get_track_count(file);
  std::cout << "Total tracks: " << track_count << std::endl;

  for (u32 i = 0; i < track_count; i++)
  {
    u32 track_id = gf_isom_get_track_id(file, i + 1);
    u32 media_type = gf_isom_get_media_type(file, i + 1);
    const char *media_type_name = gf_4cc_to_str(media_type);

    std::cout << "Track " << i + 1 << " - ID: " << track_id << ", Type: " << media_type_name << std::endl;

    if (media_type == GF_ISOM_MEDIA_VISUAL)
    {
      u32 codec = gf_isom_get_media_subtype(file, i + 1, 1);
      const char *codec_name = gf_4cc_to_str(codec);

      std::cout << "  Codec: " << codec_name << std::endl;

      if (codec == GF_ISOM_SUBTYPE_VVC1 || codec == GF_ISOM_SUBTYPE_VVI1)
      {
        std::cout << "  VVC codec detected." << std::endl;
        // VVC codec 처리 코드를 여기에 추가하세요.
      }
    }
  }

  gf_isom_close(file);
  return 0;
}
