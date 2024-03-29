#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n, m;
    cin >> n >> m;
    vector<vector<int>> matr(n+1, vector<int> (m+1, 0));
    vector<vector<int>> table(n, vector<int> (m, 0));

    table[0][0] = matr[0][0];
    int s = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        matr[n][i] = 1e9;
    }

    for (int i = 0; i < n; i++) {
        matr[i][m] = 1e9;
    }
    for (int i = 1; i < n; i++) {
        table[0][i] = matr[0][i] + table[0][i - 1];
    }

    for (int i = 1; i < n; i++) {
        table[0][i] = matr[0][i] + table[0][i - 1];
    }

    for (int i = 1; i < n; i++) {
        table[i][0] = matr[i][0] + table[i - 1][0];
    }


    int i = 0, j = 0;

    while (i < n || j < m) {
        if (matr[i][j + 1] + table[i][j] < matr[i + 1][j] + table[i][j]) {
            table[i][j+1] = matr[i][j + 1] + table[i][j];
            j++;
        }
        else {
            table[i + 1][j] = matr[i + 1][j] + table[i][j];
            i++;
        }
    }

    cout << table[i][j];

	return 0;
}

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          set(CMAKE_C_COMPILER "/usr/bin/cc")
set(CMAKE_C_COMPILER_ARG1 "")
set(CMAKE_C_COMPILER_ID "GNU")
set(CMAKE_C_COMPILER_VERSION "11.3.0")
set(CMAKE_C_COMPILER_VERSION_INTERNAL "")
set(CMAKE_C_COMPILER_WRAPPER "")
set(CMAKE_C_STANDARD_COMPUTED_DEFAULT "17")
set(CMAKE_C_EXTENSIONS_COMPUTED_DEFAULT "ON")
set(CMAKE_C_COMPILE_FEATURES "c_std_90;c_function_prototypes;c_std_99;c_restrict;c_variadic_macros;c_std_11;c_static_assert;c_std_17;c_std_23")
set(CMAKE_C90_COMPILE_FEATURES "c_std_90;c_function_prototypes")
set(CMAKE_C99_COMPILE_FEATURES "c_std_99;c_restrict;c_variadic_macros")
set(CMAKE_C11_COMPILE_FEATURES "c_std_11;c_static_assert")
set(CMAKE_C17_COMPILE_FEATURES "c_std_17")
set(CMAKE_C23_COMPILE_FEATURES "c_std_23")

set(CMAKE_C_PLATFORM_ID "Linux")
set(CMAKE_C_SIMULATE_ID "")
set(CMAKE_C_COMPILER_FRONTEND_VARIANT "")
set(CMAKE_C_SIMULATE_VERSION "")




set(CMAKE_AR "/usr/bin/ar")
set(CMAKE_C_COMPILER_AR "/usr/bin/gcc-ar-11")
set(CMAKE_RANLIB "/usr/bin/ranlib")
set(CMAKE_C_COMPILER_RANLIB "/usr/bin/gcc-ranlib-11")
set(CMAKE_LINKER "/usr/bin/ld")
set(CMAKE_MT "")
set(CMAKE_COMPILER_IS_GNUCC 1)
set(CMAKE_C_COMPILER_LOADED 1)
set(CMAKE_C_COMPILER_WORKS TRUE)
set(CMAKE_C_ABI_COMPILED TRUE)

set(CMAKE_C_COMPILER_ENV_VAR "CC")

set(CMAKE_C_COMPILER_ID_RUN 1)
set(CMAKE_C_SOURCE_FILE_EXTENSIONS c;m)
set(CMAKE_C_IGNORE_EXTENSIONS h;H;o;O;obj;OBJ;def;DEF;rc;RC)
set(CMAKE_C_LINKER_PREFERENCE 10)

# Save compiler ABI information.
set(CMAKE_C_SIZEOF_DATA_PTR "8")
set(CMAKE_C_COMPILER_ABI "ELF")
set(CMAKE_C_BYTE_ORDER "LITTLE_ENDIAN")
set(CMAKE_C_LIBRARY_ARCHITECTURE "x86_64-linux-gnu")

if(CMAKE_C_SIZEOF_DATA_PTR)
  set(CMAKE_SIZEOF_VOID_P "${CMAKE_C_SIZEOF_DATA_PTR}")
endif()

if(CMAKE_C_COMPILER_ABI)
  set(CMAKE_INTERNAL_PLATFORM_ABI "${CMAKE_C_COMPILER_ABI}")
endif()

if(CMAKE_C_LIBRARY_ARCHITECTURE)
  set(CMAKE_LIBRARY_ARCHITECTURE "x86_64-linux-gnu")
endif()

set(CMAKE_C_CL_SHOWINCLUDES_PREFIX "")
if(CMAKE_C_CL_SHOWINCLUDES_PREFIX)
  set(CMAKE_CL_SHOWINCLUDES_PREFIX "${CMAKE_C_CL_SHOWINCLUDES_PREFIX}")
endif()





set(CMAKE_C_IMPLICIT_INCLUDE_DIRECTORIES "/usr/lib/gcc/x86_64-linux-gnu/11/include;/usr/local/include;/usr/include/x86_64-linux-gnu;/usr/include")
set(CMAKE_C_IMPLICIT_LINK_LIBRARIES "gcc;gcc_s;c;gcc;gcc_s")
set(CMAKE_C_IMPLICIT_LINK_DIRECTORIES "/usr/lib/gcc/x86_64-linux-gnu/11;/usr/lib/x86_64-linux-gnu;/usr/lib;/lib/x86_64-linux-gnu;/lib")
set(CMAKE_C_IMPLICIT_LINK_FRAMEWORK_DIRECTORIES "")
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        �   $       4                                  �                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          INDX( 	                 (   h  �       �                    J#     h V     H#     ��i�}e���i�}e���i�}e���i�}e�       �              
 a n d r o i d . p y   K#     ` N     H#     /�i�}e�1�i�}e�1�i�}e�/�i�}e�        :               a p i . p y   M#     h R     H#     ��i�}e�ӊi�}e�ӊi�}e���i�}e�       ;
               m a c o s . p y       P#     ` P     H#     �i�}e��i�}e��i�}e��i�}e�        �               u n i x . p y N#     h V     H#     �i�}e�@�i�}e�@�i�}e �i�}e�P       P               
 v e r s i o n . p y   I#     h V     H#     n}i�}e�]i�}e�]i�}e�n}i�}e�                      
 w i n d o w s . p y   O#     h X     H#     }�i�}e���i�}e���i�}e�}�i�}e� @      ;2               _ _ i n i t _ _ . p y L#     h X     H#     f�i�}e�Ňi�}e�Ňi�}e�f�i�}e�       t               _ _ m a i n _ _ . p y                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        """Configuration management setup

Some terminology:
- name
  As written in config files.
- value
  Value associated with a name
- key
  Name combined with it's section (section.name)
- variant
  A single word describing where the configuration key-value pair came from
"""

import configparser
import locale
import os
import sys
from typing import Any, Dict, Iterable, List, NewType, Optional, Tuple

from pip._internal.exceptions import (
    ConfigurationError,
    ConfigurationFileCouldNotBeLoaded,
)
from pip._internal.utils import appdirs
from pip._internal.utils.compat import WINDOWS
from pip._internal.utils.logging import getLogger
from pip._internal.utils.misc import ensure_dir, enum

RawConfigParser = configparser.RawConfigParser  # Shorthand
Kind = NewType("Kind", str)

CONFIG_BASENAME = "pip.ini" if WINDOWS else "pip.conf"
ENV_NAMES_IGNORED = "version", "help"

# The kinds of configurations there are.
kinds = enum(
    USER="user",  # User Specific
    GLOBAL="global",  # System Wide
    SITE="site",  # [Virtual] Environment Specific
    ENV="env",  # from PIP_CONFIG_FILE
    ENV_VAR="env-var",  # from Environment Variables
)
OVERRIDE_ORDER = kinds.GLOBAL, kinds.USER, kinds.SITE, kinds.ENV, kinds.ENV_VAR
VALID_LOAD_ONLY = kinds.USER, kinds.GLOBAL, kinds.SITE

logger = getLogger(__name__)


# NOTE: Maybe use the optionx attribute to normalize keynames.
def _normalize_name(name: str) -> str:
    """Make a name consistent regardless of source (environment or file)"""
    name = name.lower().replace("_", "-")
    if name.startswith("--"):
        name = name[2:]  # only prefer long opts
    return name


def _disassemble_key(name: str) -> List[str]:
    if "." not in name:
        error_message = (
            "Key does not contain dot separated section and key. "
            "Perhaps you wanted to use 'global.{}' instead?"
        ).format(name)
        raise ConfigurationError(error_message)
    return name.split(".", 1)


def get_configuration_files() -> Dict[Kind, List[str]]:
    global_config_files = [
        os.path.join(path, CONFIG_BASENAME) for path in appdirs.site_config_dirs("pip")
    ]

    site_config_file = os.path.join(sys.prefix, CONFIG_BASENAME)
    legacy_config_file = os.path.join(
        os.path.expanduser("~"),
        "pip" if WINDOWS else ".pip",
        CONFIG_BASENAME,
    )
    new_config_file = os.path.join(appdirs.user_config_dir("pip"), CONFIG_BASENAME)
    return {
        kinds.GLOBAL: global_config_files,
        kinds.SITE: [site_config_file],
        kinds.USER: [legacy_config_file, new_config_file],
    }


class Configuration:
    """Handles management of configuration.

    Provides an interface to accessing and managing configuration files.

    This class converts provides an API that takes "section.key-name" style
    keys and stores the value associated with it as "key-name" under the
    section "section".

    This allows for a clean interface wherein the both the section and the
    key-name are preserved in an easy to manage form in the configuration files
    and the data stored is also nice.
    """

    def __init__(self, isolated: bool, load_only: Optional[Kind] = None) -> None:
        super().__init__()

        if load_only is not None and load_only not in VALID_LOAD_ONLY:
            raise ConfigurationError(
                "Got invalid value for load_only - should be one of {}".format(
                    ", ".join(map(repr, VALID_LOAD_ONLY))
                )
            )
        self.isolated = isolated
        self.load_only = load_only

        # Because we keep track of where we got the data from
        self._parsers: Dict[Kind, List[Tuple[str, RawConfigParser]]] = {
            variant: [] for variant in OVERRIDE_ORDER
        }
        self._config: Dict[Kind, Dict[str, Any]] = {
            variant: {} for variant in OVERRIDE_ORDER
        }
        self._modified_parsers: List[Tuple[str, RawConfigParser]] = []

    def load(self) -> None:
        """Loads configuration from configuration files and environment"""
        self._load_config_files()
        if not self.isolated:
            self._load_environment_vars()

    def get_file_to_edit(self) -> Optional[str]:
        """Returns the file with highest priority in configuration"""
        assert self.load_only is not None, "Need to be specified a file to be editing"

        try:
            return self._get_parser_to_modify()[0]
        except IndexError:
            return None

    def items(self) -> Iterable[Tuple[str, Any]]:
        """Returns key-value pairs like dict.items() representing the loaded
        configuration
        """
        return self._dictionary.items()

    def get_value(self, key: str) -> Any:
        """Get a value from the configuration."""
        try:
            return self._dictionary[key]
        except KeyError:
            raise ConfigurationError(f"No such key - {key}")

    def set_value(self, key: str, value: Any) -> None:
        """Modify a value in the configuration."""
        self._ensure_have_load_only()

        assert self.load_only
        fname, parser = self._get_parser_to_modify()

        if parser is not None:
            section, name = _disassemble_key(key)

            # Modify the parser and the configuration
            if not parser.has_section(section):
                parser.add_section(section)
            parser.set(section, name, value)

        self._config[self.load_only][key] = value
        self._mark_as_modified(fname, parser)

    def unset_value(self, key: str) -> None:
        """Unset a value in the configuration."""
        self._ensure_have_load_only()

        assert self.load_only
        if key not in self._config[self.load_only]:
            raise ConfigurationError(f"No such key - {key}")

        fname, parser = self._get_parser_to_modify()

        if parser is not None:
            section, name = _disassemble_key(key)
            if not (
                parser.has_section(section) and parser.remove_option(section, name)
            ):
                # The option was not removed.
                raise ConfigurationError(
                    "Fatal Internal error [id=1]. Please report as a bug."
                )

            # The section may be empty after the option was removed.
            if not parser.items(section):
                parser.remove_section(section)
            self._mark_as_modified(fname, parser)

        del self._config[self.load_only][key]

    def save(self) -> None:
        """Save the current in-memory state."""
        self._ensure_have_load_only()

        for fname, parser in self._modified_parsers:
            logger.info("Writing to %s", fname)

            # Ensure directory exists.
            ensure_dir(os.path.dirname(fname))

            with open(fname, "w") as f:
                parser.write(f)

    #
    # Private routines
    #

    def _ensure_have_load_only(self) -> None:
        if self.load_only is None:
            raise ConfigurationError("Needed a specific file to be modifying.")
        logger.debug("Will be working with %s variant only", self.load_only)

    @property
    def _dictionary(self) -> Dict[str, Any]:
        """A dictionary representing the loaded configuration."""
        # NOTE: Dictionaries are not populated if not loaded. So, conditionals
        #       are not needed here.
        retval = {}

        for variant in OVERRIDE_ORDER:
            retval.update(self._config[variant])

        return retval

    def _load_config_files(self) -> None:
        """Loads configuration from configuration files"""
        config_files = dict(self.iter_config_files())
        if config_files[kinds.ENV][0:1] == [os.devnull]:
            logger.debug(
                "Skipping loading configuration files due to "
                "environment's PIP_CONFIG_FILE being os.devnull"
            )
            return

        for variant, files in config_files.items():
            for fname in files:
                # If there's specific variant set in `load_only`, load only
                # that variant, not the others.
                if self.load_only is not None and variant != self.load_only:
                    logger.debug("Skipping file '%s' (variant: %s)", fname, variant)
                    continue

                parser = self._load_file(variant, fname)

                # Keeping track of the parsers used
                self._parsers[variant].append((fname, parser))

    def _load_file(self, variant: Kind, fname: str) -> RawConfigParser:
        logger.verbose("For variant '%s', will try loading '%s'", variant, fname)
        parser = self._construct_parser(fname)

        for section in parser.sections():
            items = parser.items(section)
            self._config[variant].update(self._normalized_keys(section, items))

        return parser

    def _construct_parser(self, fname: str) -> RawConfigParser:
        parser = configparser.RawConfigParser()
        # If there is no such file, don't bother reading it but create the
        # parser anyway, to hold the data.
        # Doing this is useful when modifying and saving files, where we don't
        # need to construct a parser.
        if os.path.exists(fname):
            try:
                parser.read(fname)
            except UnicodeDecodeError:
                # See https://github.com/pypa/pip/issues/4963
                raise ConfigurationFileCouldNotBeLoaded(
                    reason="contains invalid {} characters".format(
                        locale.getpreferredencoding(False)
                    ),
                    fname=fname,
                )
            except configparser.Error as error:
                # See https://github.com/pypa/pip/issues/4893
                raise ConfigurationFileCouldNotBeLoaded(error=error)
        return parser

    def _load_environment_vars(self) -> None:
        """Loads configuration from environment variables"""
        self._config[kinds.ENV_VAR].update(
            self._normalized_keys(":env:", self.get_environ_vars())
        )

    def _normalized_keys(
  