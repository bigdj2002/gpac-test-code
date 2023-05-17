#include "print_mp4_info.h"

void print_media_info(const char *input_file)
{
  GF_ISOFile *input_isom = NULL;
  GF_Err err = GF_OK;
  u32 track_count;

  input_isom = gf_isom_open(input_file, GF_ISOM_OPEN_READ, NULL);
  if (err != GF_OK)
  {
    GF_LOG(GF_LOG_ERROR, GF_LOG_CONTAINER, ("Failed to open input file: %s\n", gf_error_to_string(err)));
    return;
  }

  track_count = gf_isom_get_track_count(input_isom);

  std::cout << "----------------------------------------------------------------------------------" << std::endl;
  printf("File: %s\n", input_file);
  printf("Number of tracks: %u\n", track_count);

  for (u32 i = 0; i < track_count; i++)
  {
    u32 track_id = gf_isom_get_track_id(input_isom, i + 1);
    u32 media_type = gf_isom_get_media_type(input_isom, i + 1);
    u32 media_subtype = gf_isom_get_media_subtype(input_isom, i + 1, 1);
    u64 duration = gf_isom_get_media_duration(input_isom, i + 1);
    u32 timescale = gf_isom_get_media_timescale(input_isom, i + 1);
    u32 width = 0;
    u32 height = 0;
    if (media_type == GF_ISOM_MEDIA_VISUAL)
    {
      gf_isom_get_visual_info(input_isom, i + 1, 1, &width, &height);
    }

    printf("Track %u:\n", i + 1);
    printf("  Track ID: %u\n", track_id);
    printf("  Media type: %s\n", gf_4cc_to_str(media_type));
    printf("  Media subtype: %s\n", gf_4cc_to_str(media_subtype));
    printf("  Duration: %" PRIu64 " (%.2f seconds)\n", duration, (double)duration / timescale);
    if (width && height)
    {
      printf("  Width: %u\n", width);
      printf("  Height: %u\n", height);
    }
  }
  std::cout << "----------------------------------------------------------------------------------" << std::endl;

  gf_isom_delete(input_isom);
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    std::cerr << "Usage: " << argv[0] << " <input_file.mp4>" << std::endl;
    return 1;
  }

  const char *input_file = argv[1];
  print_media_info(input_file);

  return 0;
}
