// shanpo.c 
// By River 98.08.29
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIC"ɽ��"NOR);
        set("long",@long
�˴���ɽ·�Ե����ж��ͣ������Ӳݴ���������ȥΣ���ķ������ڽ�����
���Ź�Ĺ��ǰ��������ǰ��͵ȡ��Ĺ�ؼ������Թ�Ĺ���Ӽ�ǿ��Ѳ����һЩ��
Ĺ��������ɽ�¸���Ѳ�ߡ�
long);

        set("outdoors","��Ĺ");

        set("exits",([
          "westdown" : __DIR__"guoyuan",
          "northeast" : __DIR__"shanpo1",        
        ]));

        setup();
}


void init()
{        
       add_action("do_xunluo","xunluo");
}

int do_xunluo()
{
        mapping fam;
        object me=this_player();
        if (!living(me)) return 0;
        if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
           return notify_fail("�㲻�ǹ�Ĺ���ˣ�������ڹ�ĹѲ�ߣ�\n");
        if (me->is_busy() || me->is_fighting())
           return notify_fail("����æ���ء�\n");
        if (me->query_temp("gm/job"))
           return notify_fail("�㲻���Ѿ���Ѳ����ô��\n");
        if ( me->query_condition("gm_job" ) > 0 )
           return notify_fail("������������������ΧһƬ����������û��ʲôΣ�ա�\n");
        if ( me->query("combat_exp") < 30000)
           return notify_fail("��ľ��鲻���������ܵ���Ѳ�ߵ����Ρ�\n");
        if (me->query("combat_exp") > 120000 )
           return notify_fail("���书�Ѿ����ߣ�Ѳ�ߵ��¾���С������ȥ�ٰ�ɡ�\n");
        message_vision(HIY"$N��������ܴ����ţ�ͻȻ���ֶ��Ϸ�����һЩ������\n"NOR,me);
        me->apply_condition("gm_job", 5+random(5)); 
        me->set_temp("gm/job", 1);
        return 1;
}
