inherit ROOM;

void create()
{
set("short", "��ʯ");
        set("long",@long
��ɽ������һ���ʯ����ʯ�������������ʯ���ഫ������ɮ�����ڴ�
��ʯ�ľ���������ʯ��Ϣ����ʯ�����������ģ�����ơ�����ʯ����������
��������Ц��Ե���Ĵ�˵����������ԧ��ʯ��������ʯ��ʵϵ��ӿɽ���
long);
set("outdoors", "suzhou");
set("objects",([
__DIR__"npc/dao-ke" : 2,
]));
set("exits",([
"south" : __DIR__"shijianshi",
]));
setup();
}
