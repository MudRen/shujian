// Room: /d/jiaxing/nanhu1.c

inherit ROOM;

void create()
{
	set("short", "�Ϻ�");
	set("long", @LONG
�������̲������Ϻ������ϼ�ֻ�������ε������ϵ��οͺ���¥Ů����
��Ц����ˮ���û�д��Ƕɲ���ȥ�ġ�����֪��˭�ں��׶���һЩľ׮��׮
��Ǳ��ˮ��֮��һ����ĵط�����ʹ�ǲ����Ṧ��������ȥҲ����ˮ��Ư����
�ӡ�
LONG
	);

	set("exits", ([
		"south" : "/d/group/entry/jxyanyu",
                "northwest" : __DIR__ "nanhu",
	]));

	set("outdoors", "����");
	setup();
}
