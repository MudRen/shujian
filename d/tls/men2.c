inherit ROOM;
void create()
{
        set("short", "�����");
        set("long",@LONG
�ɹ�������ţ��������й���ס��������Ԫ�������ʴ�ʿԺ��
��һ·���ݶ�������ɮ��������֮�أ����������ߣ����ҷ���˿����
�졣����ͨ�����Ҹ�
LONG);
	set("outdoors","������");
        set("exits", ([
		"north" : __DIR__"wuwoge",
                "west": __DIR__"yz5",
                "east": __DIR__"gfd",
	]));
        set("coor/x",-360);
  set("coor/y",-320);
   set("coor/z",20);
   setup();
}
int valid_leave(object me, string dir)
{
        if (me->query("gender") == "Ů��" && dir =="north")
           return notify_fail("���Ҹ����������ǽ��㻹Ըʱ����Ϣ֮������һ��Ů��Ҫ��ȥ���²�̫�ðɣ�\n");
        return ::valid_leave(me, dir);
}


