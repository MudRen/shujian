#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
���ֽ�����������ǰ������һ������ʯ�������ֱͨ��ǰ�����ص�ϡ
ϡ��������ż��ð�����ȴ�Եøߴ�ͦ�Σ��������֦������ո߸���չ��
���������˼䣬�����Ĵ�����(zhangwang)������Щ����������
��Ҫ�뿪�͸Ͻ��뿪��(leave)��
LONG
        );

 set("outdoors", "shaolin");    
set("no_fight", 1);
   set("exits", ([
                 "leave" : "/d/wudang/houyuan",
]));
   setup();
}
void init()
{
	add_action("do_zhangwang","zhangwang");
}
int do_zhangwang()
{
	object me = this_player();
	
	if( (int)me->is_busy() || me->is_fighting()) 
		return notify_fail("����æ���ء�\n");
        if(!me->query_temp("wdjiuyang1"))
               return notify_fail("����ô��������ģ�\n");
tell_object(me,WHT"���ִ�����쳤�����Ĵ�������ȴ��֪������ӿ��һ��ɮ����\n"NOR); 
tell_object(me,WHT"Ϊ�׵���һ����ɫ��������ɮ��ֻ������ɮ������ɮ������\n"
                  HIR"\n����Ħ���ڵ���һ����ǰ������С�������ˡ���\n"NOR);

remove_call_out("meet");
call_out("meet", 2);
me->delete_temp("wdjiuyang1");
return 1;
}
int meet(object me)
{
me = this_player();
tell_object(me,WHT"\n�㵱�´󺧣����룺�ҷ���ʲô�����������˴����\n"NOR);   
tell_object(me,WHT"��Ħ�ò�����������ô���Լ�������ܵ�����ȥ�ˣ�\n"NOR);  
tell_object(me,WHT"\n���ڲ�֪����֮�У��Ǵ�Ħ�����޺����ڵ��ӵ�ʱ�������ѽ�\n"
                  "һ����ɮ��һ�������һ����ŮΧ���м䡣�����������޴�,\n"
                 "˵������ʦ�����ҡ����ҡ�����\n"NOR);
tell_object(me,HIR"\n������������ɮ�ȵ������������֣�������ʱ����\n"NOR);   
remove_call_out("meet1");
        call_out("meet1", 2, me);
        return 1;
}
int meet1(object me)
{
me = this_player();
tell_object(me,HIG"\n���ԭ��������Ҫ�����㣬�����Կ�ȴ��Ҳ������Ҳ���ǡ�\n"NOR);  
tell_object(me,WHT"\n�Ǳ�Χ����ɮ��Ͼ˼���������ת�˸�Ȧ�ӣ�����ֻ����Ͱ����\n"
                    "������һ�㾢��Ƶ���ɮ������ǰ�����Ż�Ͱһ����Ͱ����ˮ��\n"
                    "���˳��������˫Ͱ�����Ͱ��������Ů���ұ���Ͱ�����㣬��\n"
                    "ת�߰˸�Ȧ�ӣ��ǶԴ���Ͱ��������ޱȵ�����ʹ������������\n"
                    "���Ǵ�һ�㣬���ǧ��֮������˭�ܵ��ã���Ħ���ڵ��ӷ׷����ܡ�\n"NOR);

remove_call_out("meet2");
        call_out("meet2", 2, me);
        return 1;
}
int meet2(object me)
{
me = this_player();
tell_object(me,HIG"\n����������������СŮ�����������꣬˭֪����֮���������ˣ�\n"
                    "����������ͱ��ȴ��Ȼ��������Ҳ���н��������������������\n"
                    "����ɮ������ɣ������죬��ֻ�����߷�����Х�����������\n"
                    "ȴ���ϼ��ѣ�ֻ������ȥ��......\n"NOR); 
  me->set_temp("wdjiuyang2",1);
me->move("kungfu/class/wudang/shenshan");
        return 1;
}
