inherit ROOM;
void create()
{
        set("short", "�����");
        set("long",@LONG
�ɹ�������ţ������й����౦���������š��嶼��̨����
�޾����껨Ժ��������̨����һ·���ݶ�������ɮ��������֮�أ���
�������ߣ����ҷ���˿�����졣����ͨ���޾���
LONG);
	set("outdoors","������");
        set("exits", ([
             "north" : __DIR__"wujingge",
	       "west": __DIR__"gfd",
	       "east": __DIR__"yz4",
	]));
        set("coor/x",-340);
  set("coor/y",-320);
   set("coor/z",30);
   setup();
}
int valid_leave(object me, string dir)
{
        if (me->query("gender") != "Ů��" && dir =="north")
           return notify_fail("�޾��������������С���ǽ��㻹Ըʱ����Ϣ֮������Ҫ��ȥ���²�̫�ðɣ�\n");
        return ::valid_leave(me, dir);
}
