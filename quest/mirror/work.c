// work.c modified by system_3

inherit ROOM;

int cot;
void create()
{
        set("short", "谷物加工厂");
        set("long", @LONG
这是一间谷物加工厂，这里是谷子脱壳成米的地方。米厂老板是一
个一看就知道是十分精明的干瘦的中年人，老是带着一脸奸笑。你可以
看到许多人正在忙忙碌碌的工作着，门口挂著一块牌子。
LONG
        );
        set("no_sleep_room",1);
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dongmen",
]));

        setup();
}

//是镜像
int is_mirror() { return 1; }