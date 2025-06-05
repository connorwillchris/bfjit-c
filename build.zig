const std = @import("std");

pub fn build(b: *std.Build) void {
    const e = b.addExecutable(.{
        .name = "bfjit",
        .target = b.graph.host,
    });

    e.linkLibC();
    b.installArtifact(e);
    e.addCSourceFiles(.{ .files = &.{
        "src/main.c",
    } });
}
