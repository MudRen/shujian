// guidao.c
// by cleansword
// 96-02-16 YZC disabled NPC killing, & "unknown" problem when revealed

#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
	set_name("��ʬ", ({ "jiang shi", "jiang" , "shi" }) );
	 set("title", HIB"Թ��"NOR);

	set("gender", "����" );
	set("shen_type", -1);
	set("age", 25);
	set("str", 25);
	set("cor", 25);
	set("cps", 25);
	set("int", 25);
	set("long",
	"���Ǹ��׶�����Ľ�ʬ����ɫ֮���������տտ���⣬��Ϊ�}�ˡ�\n" );

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
 if (!arg) return notify_fail("��Ҫ����˭��\n");
if (!ob || !living(ob)) return notify_fail("��Ҫ����˭��\n");

 message_vision(HIB"\n$N�̵���ǰ����$n"HIB"���һ�����η����������ߣ�\n"NOR, me, ob);
message_vision(HIB"\nͨ��֮�£�һ����ʿ������ʬ��û��������$n��$N��Ȼ���˷�����\n"
                    "һʱ����һ����$N��״���������ǣ���ǰֱȡ$n��˫��ս��һ����\n"NOR, me, ob);

remove_call_out("do_yuanxing");
call_out("do_yuanxing", 2, me);

return 1;
}        
int do_yuanxing(object me)
{
object ob = this_object();
object ob1 = new("quest/xyfm/npc/killer");
message_vision(HIR"\nս�˼��ϣ�$N��$n���Ǵ������׺��쳣����������������������Ц��\n"NOR, me, ob);
ob1->move(environment(me));
message_vision(HIR"\n$n����ԽսԽ�ӣ�һ���������ϵĽ�ʬ���ֵ����ڵأ�ԭ��$n�����˼ٰ���ɵġ�\n"NOR, me, ob);
destruct(ob);


return 1;
}


