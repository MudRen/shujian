// update by Lklv for new nanyang city 2001.10.11

#include <ansi.h>
inherit ROOM;

void meet();
void create()
{
        set("short", "Ħ����");
        set("long", @LONG
������һ��ʮ�־�����ɽ�£��ųơ�Ħ���¡�������ɽ�紵����������Ƣ��
LONG
        );
        set("outdoors", "��������");
        set("exits", ([
                "down" :"/d/group/entry/mjshan2",
                 "up" :"/d/xiangyang/mtyd",
        ]));
 
  setup();

}

void init()
{
 remove_call_out("meet");
call_out("meet",1);
}
void meet()
{
 object me , ob , ob1;
me = this_player();
ob =new("/d/xiangyang/npc/zhangsan");
ob1 =new("/d/xiangyang/npc/lisi");
if (me->query_temp("taixuan/ask"))
{
ob->move(environment(me));
ob1->move(environment(me));

tell_object(me, HIC "\n������뿪��ͻȻ��Ӱһ�Σ���ǰһ���� "
"\n������װ���Ĺ����Ѿ��߽�������ǰ��"
               "\n����һ��һ����һ��һ�ݣ���ӳ��Ȥ��\n" NOR, me);

remove_call_out("meet");
me->delete_temp("taixuan/ask");
me->set_temp("taixuan/ask2",1);
call_out("meet1",3);
}
return ;
}

int meet1(object me)
{
object ob,ob1;
ob=present("zhang san",this_object());
ob1=present("li si",this_object());
me = this_player();

message_vision  (HIC "\n���ݸ߸�����߹�����������ʹ��������"
"\nֻ������˵��������ݼ�Ȼ���ˣ��ͽ�����������ɣ���"
"\n������������֮����$Nһʱ�ֲ����ǵ����ѡ�\n" NOR, me);
remove_call_out("meet1");
call_out("meet2",2);

return 1;
}

int meet2(object me)
{
object ob,ob1;
ob=present("zhang san",this_object());
ob1=present("li si",this_object());
me = this_player();
message_vision (HIC "\n$N���´󺧣��������书�ظ�ǿ��������Ϣ��"
"\n������߶�������������ʱ��һ���׹�һ��"
"\nһ���ѵ���ǰ��ֻ����������ȥ��ȡ��"
"\nֻ����һ���������³��ˣ��������ǰ�����͵�һ�ۣ���"
"\n���ٿ�ʱ��������������Զ�ڰ��￪�⡣\n" NOR, me);
destruct(ob);
destruct(ob1);

remove_call_out("meet2");

me->delete_temp("taixuan/ask2");
call_out("meet3",2);

return 1;

}

int meet3(object me)
{
        object ob;
        int exp, pot, sc;

       
        ob =new("/d/xiangyang/npc/obj/qingtie");
        me = this_player();


        if (me->query("kar") > 20)
        {
                message_vision( HIR "\n$N" HIR "���һ�������뵽�ʲŶ�������֮�"
                               "˵ʱ��������ʵֻ����̣�������һ��\nǡǡ��������"
"��ͷһ��ʱ��ֻ����һ����������д�������³��ˣ����͵�����\n" NOR, me);
                
                ob->move(me, 1);
me->set_temp("taixuan/qingtie",1);

 CHANNEL_D->do_channel(this_object(), "rumor", HIW""+me->query("name")+"�õ�һ�����͵�������");
                
                                           } else
        {
                message_vision( HIR "\n$N" HIR "���һ�������뵽�ʲŶ�������֮�"
                               "˵ʱ��������ʵֻ����̣�$N����һ��\nȴ������������"
"���ң�$N" HIR "һ������ס�����ڵ��Ͼ�Ȼʧȥ�ټ���\n" NOR, me);
                                       }
me->delete_temp("taixuan/1");
        return 1;
}





