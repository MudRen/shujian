// /d/xiangyang/lantian.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Թų������񣬲������ʺã�Ҳ������ҩ���������ǳ�������������
����ȥ��������·��
LONG
        );
        set("outdoors", "����");

        set("exits", ([
            "southeast" : __DIR__"shanxiroad2",
                "north" : "/d/changan/southroad3",
        ]));

        setup();
}


void init() 
 {
           add_action("do_push", "huigong");
 }
 int do_push()
 {
           object me = this_player();
           if (me->is_busy() || me->is_fighting())
                  return notify_fail("����æ���ء�\n");
if(me->query("family") && me->query("family/family_name")!="���չ�")
                    return notify_fail("ʲô?\n");

       message_vision("$N����˵������ů������Ѱ�٣���������߷����л�ü�Ʒ����һ������ϲ֮�࣬���Ÿ�·��ǰ�����գ�������歡�\n", me);
           me->receive_damage("jing", 30);
           me->start_busy(random(3));
         message_vision("$N���´ҴҸ�·����ת���֣����������ǵ���Ʈ��塣\n", me);
  me->move("/d/tianshan/pmfeng");
           return 1;
 }

