// guidao.c
// by cleansword
// 96-02-16 YZC disabled NPC killing, & "unknown" problem when revealed

#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
	set_name("僵尸", ({ "jiang shi", "jiang" , "shi" }) );
	 set("title", HIB"怨孽"NOR);

	set("gender", "男性" );
	set("shen_type", -1);
	set("age", 25);
	set("str", 25);
	set("cor", 25);
	set("cps", 25);
	set("int", 25);
	set("long",
	"这是个凶恶阴冷的僵尸，月色之下两颗獠牙湛湛泛光，颇为瘆人。\n" );

	set("combat_exp", 20000);
	
	
	setup();
	
}
void init()
{
object me = this_player();
add_action("do_xiangfu","xiangfu");

::init();
}

int do_xiangfu(string arg)
{
 object me = this_player();
object ob = this_object();
 if (!arg) return notify_fail("你要降伏谁？\n");
if (!ob || !living(ob)) return notify_fail("你要降伏谁？\n");

 message_vision(HIB"\n$N仗胆上前，对$n"HIB"大喝一声：何方妖孽，休走！\n"NOR, me, ob);
message_vision(HIB"\n通常之下，一般人士见到僵尸皆没命逃亡，$n见$N竟然不退反进，\n"
                    "一时心中一怔，$N见状，胆气大涨，上前直取$n，双方战在一处。\n"NOR, me, ob);

remove_call_out("do_yuanxing");
call_out("do_yuanxing", 2, me);

return 1;
}        
int do_yuanxing(object me)
{
object ob = this_object();
object ob1 = new("quest/xyfm/npc/killer");
message_vision(HIR"\n战了几合，$N见$n并非传闻中凶狠异常，不禁豪气顿生，纵声长笑。\n"NOR, me, ob);
ob1->move(environment(me));
message_vision(HIR"\n$n则是越战越怯，一不留神，身上的僵尸面罩掉落在地，原来$n竟是人假扮而成的。\n"NOR, me, ob);
destruct(ob);


return 1;
}


