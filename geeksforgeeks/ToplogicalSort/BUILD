cc_library (
    name = "Graph",
    hdrs = ["Graph.h"]
)
cc_binary(
    name = "ToplogicalSort.main",
    srcs = ["main.cc"],
    deps = [
        "//ThirdParty/PrettyPrinter:PrettyPrinter",
        ":Graph",
    ],
)

