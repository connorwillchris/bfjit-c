const std = @import("std");

pub fn build(b: *std.Build) void {
    const e = b.addExecutable(.{
        .name = "bfjit",
        .target = b.graph.host,
    });

    e.linkLibC();
    b.installArtifact(e);
    e.addCSourceFiles(.{ .files = &.{
        // convenience comment
        "src/main.c",
        "src/bf.c",
    } });

    const run_exe = b.addRunArtifact(e);
    const run_step = b.step("run", "Run the application.");
    run_step.dependOn(&run_exe.step);
}
