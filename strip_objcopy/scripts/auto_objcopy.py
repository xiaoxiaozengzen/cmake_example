import os
import subprocess
import argparse

objcopy = "objcopy"


def is_shared_object(filename):
    return filename.endswith(".so") or ".so." in filename


def objcopy_add_gunu_debuglink(so_path, debug_path):
    """
    Adds a GNU debug link to the shared object file.
    """
    for root, _, files in os.walk(so_dir):
        for file in files:
            if not is_shared_object(file):
                continue

            so_path = os.path.join(root, file)
            debug_file = f"{file}.debug"
            debug_path = os.path.join(debug_dir, debug_file)

            if not os.path.exists(debug_path):
                print(f"[WARN] Debug file not found: {debug_path}")
                continue

            print(f"[INFO] Adding debuglink for: {so_path}")
            cmd = f"{objcopy} --add-gnu-debuglink={debug_path} {so_path}"
            ret = os.system(cmd)
            if ret != 0:
                print(f"[ERROR] Failed to add debuglink to {so_path}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Process args.")
    parser.add_argument(
        "--so-path",
        "-s",
        dest="so_path",
        type=str,
        required=True,
        help="so path to process",
    )
    parser.add_argument(
        "--debug-path",
        "-d",
        dest="debug_path",
        type=str,
        required=True,
        help="debig path to process",
    )
    args = parser.parse_args()
    so_path = args.so_path
    debug_path = args.debug_path
    print(f"[INFO] so_path: {so_path}, debug_path: {debug_path}")
    objcopy_add_gunu_debuglink(so_path, debug_path)
