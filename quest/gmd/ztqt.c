#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIY"总坛前厅"NOR);
        set("long",@LONG
这里是明教总坛的前厅，虽谓之为前厅，但极似大殿。厅前有两条大石狮，
大石狮之间是十余级的斜斜而上的石阶，石阶被一大岩石做成的石碑中间隔开，
石碑平行于石阶镶于地上。石碑上雕着一飞腾而上的火焰，极是雄伟壮观，石
碑中有一些用小楷雕刻而成的文字，记载着明教上千年的历史，还有历代明教
教主的名字。整个大厅由几条巨木支撑而起，巨上雕刻着巨龙含着火焰飞腾之
像。由此而上就是光明顶了。
LONG);
        set("exits",([
                "houtu" : __DIR__"houtu",
                "ruijin" : __DIR__"ruijin",
 "jumu" : __DIR__"jumu",
                "liehuo" : __DIR__"liehuo",
"hongshui" : __DIR__"hongshui",
        ]));
        
        setup();
}
//是镜像
int is_mirror() { return 1; }