inherit ROOM;

void create()
{
set("short", "����Ĺ");
        set("long",@long
���Խ�ʯ������ǹ�����Ĺ������Ҳ�������ʷ֮�����佭�ϣ���
ƭ���������¥������Ϊ����٣��Ծ���֮��������ͤ���ϣ�Ĺǰʯ�̡���
�ꡱ���֣�Ĺ�ϱ��Ի��ܡ��ƴ��׾��׵�ʫ��ī�ͷ׷�Ϊ֮��ʫ����������
֮���ҡ�
long);
 set("outdoors", "suzhou");
set("exits",([
"north" : __DIR__"sunwuting",
"southwest" : __DIR__"shijianshi",
]));
setup();
}
