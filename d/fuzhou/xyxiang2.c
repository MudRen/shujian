// Room: /d/fuzhou/xyxiang2.c ������
// Lklv 2001.9.6
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��С���Ϊ���ߵķ��Ӵ���Ѿ��ķϣ�����ƽ������û��ʲô��
����ԶԶ�Ŀ��Կ�������м����������ɹ̫�������Ӷ�����һ����������
լԺ��Ժ���ﳤ�˺ܸߵ���ݡ�
LONG
	);

	set("exits", ([
        	"north" : __DIR__"xyxiang",
        	"east" : __DIR__"laozhai",
	]));

	set("outdoors", "����");
	setup();
}
