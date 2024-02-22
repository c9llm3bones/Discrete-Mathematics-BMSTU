<?xml version="1.0" encoding="UTF-8"?>
<project version="4">
  <component name="AutoImportSettings">
    <option name="autoReloadType" value="ALL" />
  </component>
  <component name="ChangeListManager">
    <list default="true" id="85c34800-647d-4cbc-9107-fa475548c1a1" name="Changes" comment="" />
    <option name="SHOW_DIALOG" value="false" />
    <option name="HIGHLIGHT_CONFLICTS" value="true" />
    <option name="HIGHLIGHT_NON_ACTIVE_CHANGELIST" value="false" />
    <option name="LAST_RESOLUTION" value="IGNORE" />
  </component>
  <component name="FileTemplateManagerImpl">
    <option name="RECENT_TEMPLATES">
      <list>
        <option value="Go File" />
      </list>
    </option>
  </component>
  <component name="GOROOT" url="file://$USER_HOME$/sdk/go1.20.1" />
  <component name="ProjectId" id="2PkShM2KILT4eJ8NZm8iEv1S392" />
  <component name="ProjectViewState">
    <option name="hideEmptyMiddlePackages" value="true" />
    <option name="showLibraryContents" value="true" />
  </component>
  <component name="PropertiesComponent"><![CDATA[{
  "keyToString": {
    "DefaultGoTemplateProperty": "Go File",
    "RunOnceActivity.OpenProjectViewOnStart": "true",
    "RunOnceActivity.ShowReadmeOnStart": "true",
    "RunOnceActivity.go.formatter.settings.were.checked": "true",
    "RunOnceActivity.go.migrated.go.modules.settings": "true",
    "RunOnceActivity.go.modules.go.list.on.any.changes.was.set": "true",
    "WebServerToolWindowFactoryState": "false",
    "go.import.settings.migrated": "true",
    "last_opened_file_path": "/home/kostya",
    "node.js.detected.package.eslint": "true",
    "node.js.selected.package.eslint": "(autodetect)"
  }
}]]></component>
  <component name="RunManager">
    <configuration name="go build main.go" type="GoApplicationRunConfiguration" factoryName="Go Application" nameIsGenerated="true">
      <module name="Polish" />
      <working_directory value="$PROJECT_DIR$" />
      <kind value="FILE" />
      <directory value="$PROJECT_DIR$" />
      <filePath value="$PROJECT_DIR$/main.go" />
      <method v="2" />
    </configuration>
  </component>
  <component name="SpellCheckerSettings" RuntimeDictionaries="0" Folders="0" CustomDictionaries="0" DefaultDictionary="application-level" UseSingleDictionary="true" transferred="true" />
  <component name="TypeScriptGeneratedFilesManager">
    <option name="version" value="3" />
  </component>
  <component name="VgoProject">
    <integration-enabled>false</integration-enabled>
    <settings-migrated>true</settings-migrated>
  </component>
</project>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         package main

//дореализовать сравнение по кол-ву ребер и

import (
	"fmt"
)

var used [100000000]bool

var d = make(map[int]int)

func main() {
	n, m := 0, 0
	fmt.Scanln(&n)
	fmt.Scanln(&m)
	edges := make([][]int, n)
	ans := make([][]int, n)

	for i := 0; i < m; i++ {
		x, y := 0, 0
		fmt.Scanln(&x)
		fmt.Scanln(&y)
		if x == y {
			d[i] += 1
			continue
		}
		edges[x] = append(edges[x], y)
		edges[y] = append(edges[y], x)
	}
	ed := 0
	for i := 0; i < n; i++ {
		if len(edges[i]) != 0 {
			ed, ans = dfs(edges, edges[i][0], i, 0, ans)
			fmt.Print(ans[i])
			fmt.Print(" :")
			fmt.Println(ed)
		}

	}

	/*
		for i, v := range d {
			if mx < v {
				mx = v

			}
		}
	*/
}

func dfs(edges [][]int, v, i, val int, ans [][]int) (int, [][]int) {

	ans[i] = append(ans[i], v)
	used[v] = true
	d[i] += 1

	for _, el := range edges[v] {
		if !used[el] {
			dfs(edges, el, i, val, ans)
			val += 1
		}
	}
	return val, ans
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   {
	"artifacts" : 
	[
		{
			"path" : "lab_7"
		}
	],
	"backtrace" : 1,
	"backtraceGraph" : 
	{
		"commands" : 
		[
			"add_executable"
		],
		"files" : 
		[
			"CMakeLists.txt"
		],
		"nodes" : 
		[
			{
				"file" : 0
			},
			{
				"command" : 0,
				"file" : 0,
				"line" : 6,
				"parent" : 0
			}
		]
	},
	"compileGroups" : 
	[
		{
			"compileCommandFragments" : 
			[
				{
					"fragment" : "-g -fdiagnostics-color=always"
				}
			],
			"language" : "CXX",
			"languageStandard" : 
			{
				"backtraces" : 
				[
					1
				],
				"standard" : "17"
			},
			"sourceIndexes" : 
			[
				0,
				1
			]
		}
	],
	"id" : "lab_7::@6890427a1f51a3e7e1df",
	"link" : 
	{
		"commandFragments" : 
		[
			{
				"fragment" : "-g",
				"role" : "flags"
			},
			{
				"fragment" : "",
				"role" : "flags"
			}
		],
		"language" : "CXX"
	},
	"name" : "lab_7",
	"nameOnDisk" : "lab_7",
	"paths" : 
	{
		"build" : ".",
		"source" : "."
	},
	"sourceGroups" : 
	[
		{
			"name" : "Source Files",
			"sourceIndexes" : 
			[
				0,
				1
			]
		},
		{
			"name" : "Header Files",
			"sourceIndexes" : 
			[
				2
			]
		}
	],
	"sources" : 
	[
		{
			"backtrace" : 1,
			"compileGroupIndex" : 0,
			"path" : "main.cpp",
			"sourceGroupIndex" : 0
		},
		{
			"backtrace" : 1,
			"compileGroupIndex" : 0,
			"path" : "Stack.cpp",
			"sourceGroupIndex" : 0
		},
		{
			"backtrace" : 1,
			"path" : "Stack.h",
			"sourceGroupIndex" : 1
		}
	],
	"type" : "EXECUTABLE"
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   INDX( 	                 (   �  �       �                    w#     h V     r#     Rj�}e�� j�}e�� j�}e�Rj�}e�                      
 a d a p t e r . p y   y#     h R     r#     �$j�}e��%j�}e��%j�}e��$j�}e�       %               c a c h e . p y       }#     ` N     r#     g/j�}e�46j�}e�46j�}e�g/j�}e�                        c a c h e s   t#     h T     r#     Aj�}e��j�}e��j�}e�Aj�}e�       �              	 c o m p a t . p y     v#     p \     r#     Pj�}e�/j�}e /j�}e�Pj�}e� @      E7               c o n t r o l l e r . p y     u#     p ^     r#     �j�}e�'j�}e�'j�}e��j�}e�       �	               f i l e w r a p p e r . p y   s#     p \     r#     �j�}e�j�}e�j�}e��j�}e�       �               h e u r i s t i c s . p y     |#     p Z     r#     A,j�}e�B.j�}e�B.j�}e�A,j�}e�        �               s e r i a l i z e . p y       x#     h V     r#     �!j�}e�S#j�}e�S#j�}e��!j�}e�       �              
 w r a p p e r . p y  z#     ` P     r#     .'j�}e��(j�}e��(j�}e�.'j�}e�                      _ c m d . p y {#     h X     r#     �)j�}e��*j�}e��*j�}e��)j�}e�0      .               _ _ i n i t _ _ . p y                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 import functools
import logging
import os
from typing import TYPE_CHECKING, Dict, List, Optional, Set, Tuple, cast

from pip._vendor.packaging.utils import canonicalize_name
from pip._vendor.resolvelib import BaseReporter, ResolutionImpossible
from pip._vendor.resolvelib import Resolver as RLResolver
from pip._vendor.resolvelib.structs import DirectedGraph

from pip._internal.cache import WheelCache
from pip._internal.index.package_finder import PackageFinder
from pip._internal.operations.prepare import RequirementPreparer
from pip._internal.req.req_install import InstallRequirement
from pip._internal.req.req_set import RequirementSet
from pip._internal.resolution.base import BaseResolver, InstallRequirementProvider
from pip._internal.resolution.resolvelib.provider import PipProvider
from pip._internal.resolution.resolvelib.reporter import (
    PipDebuggingReporter,
    PipReporter,
)

from .base import Candidate, Requirement
from .factory import Factory

if TYPE_CHECKING:
    from pip._vendor.resolvelib.resolvers import Result as RLResult

    Result = RLResult[Requirement, Candidate, str]


logger = logging.getLogger(__name__)


class Resolver(BaseResolver):
    _allowed_strategies = {"eager", "only-if-needed", "to-satisfy-only"}

    def __init__(
        self,
        preparer: RequirementPreparer,
        finder: PackageFinder,
        wheel_cache: Optional[WheelCache],
        make_install_req: InstallRequirementProvider,
        use_user_site: bool,
        ignore_dependencies: bool,
        ignore_installed: bool,
        ignore_requires_python: bool,
        force_reinstall: bool,
        upgrade_strategy: str,
        py_version_info: Optional[Tuple[int, ...]] = None,
    ):
        super().__init__()
        assert upgrade_strategy in self._allowed_strategies

        self.factory = Factory(
            finder=finder,
            preparer=preparer,
            make_install_req=make_install_req,
            wheel_cache=wheel_cache,
            use_user_site=use_user_site,
            force_reinstall=force_reinstall,
            ignore_installed=ignore_installed,
            ignore_requires_python=ignore_requires_python,
            py_version_info=py_version_info,
        )
        self.ignore_dependencies = ignore_dependencies
        self.upgrade_strategy = upgrade_strategy
        self._result: Optional[Result] = None

    def resolve(
        self, root_reqs: List[InstallRequirement], check_supported_wheels: bool
    ) -> RequirementSet:
        collected = self.factory.collect_root_requirements(root_reqs)
        provider = PipProvider(
            factory=self.factory,
            constraints=collected.constraints,
            ignore_dependencies=self.ignore_dependencies,
            upgrade_strategy=self.upgrade_strategy,
            user_requested=collected.user_requested,
        )
        if "PIP_RESOLVER_DEBUG" in os.environ:
            reporter: BaseReporter = PipDebuggingReporter()
        else:
            reporter = PipReporter()
        resolver: RLResolver[Requirement, Candidate, str] = RLResolver(
            provider,
            reporter,
        )

        try:
            try_to_avoid_resolution_too_deep = 2000000
            result = self._result = resolver.resolve(
                collected.requirements, max_rounds=try_to_avoid_resolution_too_deep
            )

        except ResolutionImpossible as e:
            error = self.factory.get_installation_error(
                cast("ResolutionImpossible[Requirement, Candidate]", e),
                collected.constraints,
            )
            raise error from e

        req_set = RequirementSet(check_supported_wheels=check_supported_wheels)
        for candidate in result.mapping.values():
            ireq = candidate.get_install_requirement()
            if ireq is None:
                continue

            # Check if there is already an installation under the same name,
            # and set a flag for later stages to uninstall it, if needed.
            installed_dist = self.factory.get_dist_to_uninstall(candidate)
            if installed_dist is None:
                # There is no existing installation -- nothing to uninstall.
                ireq.should_reinstall = False
            elif self.factory.force_reinstall:
                # The --force-reinstall flag is set -- reinstall.
                ireq.should_reinstall = True
            elif installed_dist.version != candidate.version:
                # The installation is different in version -- reinstall.
                ireq.should_reinstall = True
            elif candidate.is_editable or installed_dist.editable:
                # The incoming distribution is editable, or different in
                # editable-ness to installation -- reinstall.
                ireq.should_reinstall = True
            elif candidate.source_link and candidate.source_link.is_file:
                # The incoming distribution is under file://
                if candidate.source_link.is_wheel:
                    # is a local wheel -- do nothing.
                    logger.info(
                        "%s is already installed with the same version as the "
                        "provided wheel. Use --force-reinstall to force an "
                        "installation of the wheel.",
                        ireq.name,
                    )
                    continue

                # is a local sdist or path -- reinstall
                ireq.should_reinstall = True
            else:
                continue

            link = candidate.source_link
            if link and link.is_yanked:
                # The reason can contain non-ASCII characters, Unicode
                # is required for Python 2.
                msg = (
                    "The candidate selected for download or install is a "
                    "yanked version: {name!r} candidate (version {version} "
                    "at {link})\nReason for being yanked: {reason}"
                ).format(
                    name=candidate.name,
                    version=candidate.version,
                    link=link,
                    reason=link.yanked_reason or "<none given>",
                )
                logger.warning(msg)

            req_set.add_named_requirement(ireq)

        reqs = req_set.all_requirements
        self.factory.preparer.prepare_linked_requirements_more(reqs)
        return req_set

    def get_installation_order(
        self, req_set: RequirementSet
    ) -> List[InstallRequirement]:
        """Get order for installation of requirements in RequirementSet.

        The returned list contains a requirement before another that depends on
        it. This helps ensure that the environment is kept consistent as they
        get installed one-by-one.

        The current implementation creates a topological ordering of the
        dependency graph, while breaking any cycles in the graph at arbitrary
        points. We make no guarantees about where the cycle would be broken,
        other than they would be broken.
        """
        assert self._result is not None, "must call resolve() first"

        graph = self._result.graph
        weights = get_topological_weights(
            graph,
            expected_node_count=len(self._result.mapping) + 1,
        )

        sorted_items = sorted(
            req_set.requirements.items(),
            key=functools.partial(_req_set_item_sorter, weights=weights),
            reverse=True,
        )
        return [ireq for _, ireq in sorted_items]


def get_topological_weights(
    graph: "DirectedGraph[Optional[str]]", expected_node_count: int
) -> Dict[Optional[str], int]:
    """Assign weights to each node based on how "deep" they are.

    This implementation may change at any point in the future without prior
    notice.

    We take the length for the longest path to any node from root, ignoring any
    paths that contain a single node twice (i.e. cycles). This is done through
    a depth-first search through the graph, while keeping track of the path to
    the node.

    Cycles in the graph result would result in node being revisited while also
    being it's own path. In this case, take no action. This helps ensure we
    don't get stuck in a cycle.

    When assigning weight, the longer path (i.e. larger length) is preferred.
    """
    path: Set[Optional[str]] = set()
    weights: Dict[Optional[str], int] = {}

    def visit(node: Optional[str]) -> None:
        if node in path:
            # We hit a cycle, so we'll break it here.
            return

        # Time to visit the children!
        path.add(node)
        for child in graph.iter_children(node):
            visit(child)
        path.remove(node)

        last_known_parent_count = weights.get(node, 0)
        weights[node] = max(last_known_parent_count, len(path))

    # `None` is guaranteed to be the root node by resolvelib.
    visit(None)

    # Sanity checks
    assert weights[None] == 0
    assert len(weights) == expected_node_count

    return weights


def _req_set_item_sorter(
    item: Tuple[str, InstallRequirement],
    weights: Dict[Optional[str], int],
) -> Tuple[int, str]:
    """Key function used to sort install requirements for installation.

    Based on the "weight" mapping calculated in ``get_installation_order()``.
    The canonical package name is returned as the second member as a tie-
    breaker to ensure the result is predictable, which is useful in tests.
    """
    name = canonicalize_name(item[0])
    return weights[name], name
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            