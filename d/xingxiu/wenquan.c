// /d/xingxiu/silk8.c
#include <ansi.h>
inherit ROOM;

void remove_effect(object me);
void create()
{
        set("short", HIW"��ˮ��Ȫ"NOR);
        set("long", @LONG
����Ȫˮ�ڸ������ڡ������������֣�������Ȫӿ����Ϫˮ����������
�������������ڣ�����и���������ȶ������ﵽ����ˮ��Ȫ������ˮ��Ȫ
ϴԡ(swim)������ȥ�糾���Ʋ�����
LONG);
        set("no_fight", "1"); 
        set("outdoors", "yili");

        set("exits", ([
                "northeast" : __DIR__"silk8",
        ]));

        set("coor/x",-300);
  set("coor/y",100);
   set("coor/z",0);
   set("coor/x",-300);
  set("coor/y",100);
   set("coor/z",0);
   set("coor/x",-300);
 set("coor/y",100);
   set("coor/z",0);
   setup();
}
void init()
{
        add_action("do_swim", "swim");
}

int do_swim()
{     
        int skill;
        object me;
        me = this_player();   
    
        if((int)me->query_temp("swim") ) 
                return notify_fail("��������Ȫˮ���أ��ǲ�����ɵ�ˣ�\n");

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if(me->query("jing") < 300)
                return notify_fail("�����ڵľ�̫���ˣ������ܲ�����Ȫ�����ܳ����\n");

        if(me->query("qi") < 500)
                return notify_fail("�����ڵ���̫���ˣ������ܲ�����Ȫ�����ܳ����\n");
       
        if(me->query("max_neili") < 500)
                return notify_fail("�����ڵ�����̫���ˣ������ܲ�����Ȫ�����ܳ����\n");

        if(me->query("neili") < 500)
                return notify_fail("�����ڵ�����̫���ˣ������ܲ�����Ȫ�����ܳ����\n");

        if(me->query_skill("force") < 100 )
                return notify_fail("����ڹ���������������ϴ��Ȫ�к����档\n");

        if(me->query_skill("force") > 200 )
                return notify_fail("��Ŀǰ���ڹ���Ϊ����ϴҲ�޷�����������ˡ�\n");

        if( !stringp(me->query_skill_mapped("force")))
                return notify_fail("û���ڹ�������ϴ��Ȫˮ�к����档\n");
 
        message_vision("$N����������Ȫˮ�����Ѹ�ٱ�һ����������Χ��\n",me); 
        write(HIW"������ˮ�ֻ��ˮ�¼������������������ؿ�ʼ�˹��ֿ���\n"NOR);

        me->add("qi", -250);
        me->add("jing", -250);
        me->add("neili", -250);
        skill = me->query_con()*2;
        me->set_temp("swim", 1);        
        me->start_call_out( (: call_other, this_object(), "remove_effect", me:), skill);
        return 1;
}

void remove_effect(object me)
{
        me->add("qi", -250);
        me->add("jing", -250);
        me->add("neili", -250);
        me->delete_temp("swim");
//      me->improve_skill("force", me->query_skill("force")*5);   
        tell_object(me, HIW "��ֻ��ˮ��Խ��Խ�ߣ�����ڹ��Ѿ����ӵ��˼��ޣ������ˡ�����\n" NOR);
        message_vision("৵�һ����$N����Ȫˮ��վ������������Ծ�ϳرߡ�\n",me);
}

int valid_leave(object me, string dir)
{
  if(me->query_temp("swim"))
               return notify_fail("��������ˮ���ء�\n");

      return ::valid_leave(me, dir);
} 
