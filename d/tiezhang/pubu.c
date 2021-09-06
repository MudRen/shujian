//pubu.c

inherit ROOM;

void create()
{
       set("short", "�ٲ�");
       set("long", @LONG
ɽ·�е��������Զ����������ˮ����ת��һ��ɽ����ֻ��һ��������
�Ĵ��ٲ��Ӷ���˫��֮�䱼�ڶ��£���ɽ�żţ���ˮ����ɽ���м������룬��
�����Ǿ��ˡ�
LONG   );
       set("exits", ([ 
"northup" : __DIR__"xzfeng",
"eastdown" : __DIR__"sblu-1",
]));
       set("no_clean_up", 0);

       set("coor/x",-360);
  set("coor/y",-200);
   set("coor/z",60);
   setup();
}

void init()
{
       add_action("do_write",({"shuxie","write"}));
}

int do_write(string arg)
{
       object me=this_player();
       object weapon;
       int neili_lost;


       if (!living(me)) return 0;
       if (me->is_busy() || me->is_fighting()) 
                 return notify_fail("����æ���ء�\n");
       if (!me->query_temp("weapon"))
                 return notify_fail("�������ôд��? \n");
       if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "brush") 
                 return notify_fail("���õı������ԡ�\n");   
       if (!me->query_skill("brush",1))
               return notify_fail("�㲻�����ּ��ܡ�\n");
       if (me->query("jing") < 20) 
               return notify_fail("��û�취���о���\n");
       if (me->query("neili") <100)
               return notify_fail("������������ˡ�\n");
       if (me->query_skill("brush",1) < 30) 
               return notify_fail("��Ļ����ʷ�̫���ˣ��޷������鷨���⾳��\n");
       if (me->query_skill("brush",1) > 100)
               return notify_fail("���˼���룬���ſ��в�ͣ����д����ȥ�����鷨���⾳��������Ҳ�޷�����һ���ˡ�\n");
       neili_lost=(int)(me->query_skill("brush",1)/10);

       write("���˼���룬���ſ��в�ͣ����д�����鷨���⾳�����ָ�����һ�㡣\n");
       me->receive_damage("jing",20);
       me->set("neili",(int)me->query("neili")-neili_lost);
       me->improve_skill("brush", me->query_int()/2);
       return 1;
}
