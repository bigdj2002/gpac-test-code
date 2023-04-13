#include <iostream>
#include <gpac/isomedia.h>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Usage: " << argv[0] << " input.mp4" << std::endl;
    return 1;
  }

  const char *input_filename = argv[1];

  // Initialize GPAC
  gf_sys_init(GF_MemTrackerNone, NULL);

  // Open MP4 file
  GF_ISOFile *file = gf_isom_open(input_filename, GF_ISOM_OPEN_READ, nullptr);
  if (!file)
  {
    std::cerr << "Failed to open input file: " << input_filename << std::endl;
    return 1;
  }

  // Get the number of tracks
  u32 track_count = gf_isom_get_track_count(file);
  std::cout << "Number of tracks: " << track_count << std::endl;

  // Iterate over tracks
  for (u32 i = 0; i < track_count; i++)
  {
    u32 track_id = gf_isom_get_track_id(file, i + 1);
    u32 media_type = gf_isom_get_media_type(file, i + 1);
    u64 duration = gf_isom_get_media_duration(file, i + 1);

    std::cout << "Track " << i + 1 << " (ID: " << track_id << "):" << std::endl;
    std::cout << "  Media type: " << gf_4cc_to_str(media_type) << std::endl;
    std::cout << "  Duration: " << duration << std::endl;
  }

  // Close MP4 file
  gf_isom_close(file);

  // Shutdown GPAC
  gf_sys_close();

  return 0;
}
