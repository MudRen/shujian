// Room: /d/shaolin/cdian-1.c
// Date: YZC 96/01/19
// by zqb

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����Ƕ����������������Ŵ�Ħ��ʦ��������ʿ�Ļ����Լ�һЩ
����Ԫ�ϵ��ֻ�������ɢ�ҵط���������ţ�ľ��ȡ������˴��Ǳ��ɵ���
��������֮������λ����ɮ���������붨���������ĵ�����������
LONG
	);

	set("exits", ([
		"west" : __DIR__"gchang-3",
	]));

//	set("objects",([
//		__DIR__"obj/muchui" : 1,
//	]));

	set("coor/x",70);
  set("coor/y",220);
   set("coor/z",110);
   setup();
}



