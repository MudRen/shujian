// ȫ��� qixing-jian/lianzhen2 quest
//modifield by action@SJ 2008/9/18
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", HIB"�ܶ�"NOR);
	set("long", @LONG
����ȫ����������Լ��ھ���ܶ�����̫������ʱ��ֱ��ȫ�������������ڴ�ס
����������һʯ������߷���һЩʯ�룬���ϵľ�Ȼ�м���С��(hole)������͸
��С��ֱ�����������С�������к��񱱶����ǵ����У����������(yanlian)��
LONG
	);

	set("exits", ([
		"up" : __DIR__"shandong",
	]));    
	setup();
}

void init()
{
	add_action("do_yanlian", "yanlian");
}

int do_yanlian(string arg)
{
	object me;
	me = this_player();

	if( !living(me) ) return 0;

	if( (int)me->query_skill("qixing-jian", 1) < 400 )
		return notify_fail("��ı������ǽ����ȼ����㣬��ô��Ҳû���á�\n");

	if( me->is_busy() || me->is_fighting() )
		return notify_fail("����æ���ء�\n");
	
  	       
	if( arg == "����" ) {
	
			message_vision("$N��������С����������Ĺ��ߣ������������ǽ������������ʽ����\n", me);
			me->set("/quest/quanzhen/lianzhen/time",time());
      me->set("/quest/quanzhen/lianzhen/combat_exp",me->query("combat_exp"));
		    remove_call_out("canwu");
       call_out("canwu", 1, me);  
       return 1;
         }  
      return notify_fail("ʲô��\n");
         
} 							
void canwu(object me)
{
  if(!me) return;  
    remove_call_out("thinking");
    call_out("thinking", 1, me); 
    tell_object(me,HIR"����Ŵ�С���������Ĺ��ߣ������ű������ǵĲ���.........\n"NOR);
    me->start_busy(2);
}

int thinking(object me, object ob)
{
	int p;
	if(!me) return 0;
	
  if(me->query_temp("lianzhen_thinking")<(3+random(3)))
	{
		me->add_temp("lianzhen_thinking",1);
    if(random(2)) tell_object(me,WHT"\n�㰴�չ����ս�����·����ʽ,��������һ�飬�㷢����Ľ���Խ��Խ��...\n"NOR);
    else tell_object(me,HIG"\n\nͻȻ�䣬���ƺ�ץ����ʲô����ʱ�ܶ��н����ҫ�����ƺ��о����˱��������б仯...\n"NOR);
	  remove_call_out("thinking");
		call_out("thinking",3+random(3), me, ob);
	}
	else
	{
    me->delete_temp("lianzhen_thinking");

        p=random(40);

         if(p > 25 && random(me->query("kar"))>20)
    {
       tell_object(me,HIG"\n�㷢�����Ѿ���ȫ������ǽ�ڵ���ʽ����ʽ���������ױ�֮�������ʯ�ҳ�����һ��������\n"NOR);
       message_vision(HIG"\n$N������������Ц������˵������ԭ����ˣ�ԭ����ˡ���\n"NOR,me); 
       me->set("quest/quanzhen/lianzhen","pass");
       me->delete_temp("quest/lianzhen/asked");
       message_vision(HIC"\n������ս����Ĺ��ߣ�������������������ľ������ڡ���\n"NOR,me);     
    
       
	log_file("quest/quanzhen", sprintf("%s(%s) ʧ��%d�γɹ��⿪�������󡣸�Դ��%d�����飺%d��", me->name(1),me->query("id"), me->query("quest/quanzhen/lianzhen/fail"),me->query("kar"),me->query("combat_exp")) );
    }
    else
    {
       tell_object(me,HIG"\n���Ժ����ƺ�ץס��ʲô��������Ȼ����Ҫ�졣\n"NOR);
       message_vision(HIC"\n$Nҡ��ҡͷ�������������Ǻ����ѵġ���˵�գ������̾�˿�����\n"NOR,me); 
       me->add("quest/quanzhen/lianzhen/fail",1);
       me->move("d/quanzhen/shandong");
	log_file("quest/quanzhen", sprintf("%s(%s) ����������ʧ�ܣ�%d�Ρ���Դ��%d�����飺%d��", me->name(1),me->query("id"), me->query("quest/quanzhen/lianzhen/fail"),me->query("kar"),me->query("combat_exp")) );
    }
  }
  return 1;
}