// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /d/changan/duchang1
// by system_3cat 7/5/1997
inherit ROOM;


void create()
{
  set ("short", "�ư��Գ�");
  set ("long", @LONG

����֮�У������������죬����������֮��Ҳ��֪�δ�����ȥ��

LONG);

  set("item_desc",([
    "paizi" : "Ѻ��Ǭǩ�� qian dqq <amount> <money>\n"+ 
              "Ѻ����ǩ�� qian dkq <amount> <money>\n"+ 
              "ѺСǬǩ�� qian xqq <amount> <money>\n"+ 
              "ѺС��ǩ�� qian xkq <amount> <money>\n"+ 
              "ѺǬǩ��   qian qq <amount> <money>\n"+ 
              "Ѻ��ǩ��   qian kq <amount> <money>\n",
  ])); 
  set("exits", ([ /* sizeof() == 1 */
    "south" : __DIR__"chat-dc1",
  ]));

  setup();
}
//�Ǿ���
int is_mirror() { return 1; }