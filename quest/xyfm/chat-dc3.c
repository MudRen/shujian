// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /d/changan/duchang2
// by system_3cat 7/5/1997
inherit ROOM;


void create()
{
  set ("short", "�ƾɶķ�");
  set ("long", @LONG

�������һ��֧������İ��������Ĵ�֩�������ӡ�
LONG);

  set("item_desc",([
    "paizi" : "Ѻͷ������ gutou tc <amount> <money>\n"+ 
              "Ѻ˫������ gutou sd <amount> <money>\n"+ 
              "Ѻ�������� gutou qx <amount> <money>\n"+ 
              "Ѻɢ������ gutou sx <amount> <money>\n" 
  ])); 

  set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"chat-dc1",
  ]));

  setup();
}
//�Ǿ���
int is_mirror() { return 1; }
