const std = @import("std");

pub fn build(b: *std.Build) void {
    const e = b.addExecutable(.{
        .name = "bfjit",
    });

    e.addCSourceFiles(.{ .files = &.{
        "src/main.c",
    } });
}
