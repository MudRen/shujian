// Room: /d/emei/baoguosm.c

inherit ROOM;
#include <ansi.h>
#include <wanted.h>

void create()
{
	set("short", "ฑจน๚หยษฝรล");
	set("long", @LONG
ฑจน๚หยฮชถ๋แาณ๖ศ๋ึฎรลปงกฃษฝรล(gate)ษฯำะาปฟ้ด๓ุากฃหยอโฒิ้ชปทฮภฃฌดไ
ฐุัฺำณกฃำษดหาปยทฯ๒ฮ๗ษฯฟชสผตวถ๋แาษฝฃฌฑฑรๆฯยษฝสวาปฬ๕อไอไตฤสฏฝืยทกฃ
LONG
	);
	set("outdoors", "ถ๋รผษฝ");
	set("item_desc",([
	"gate" :  HIW "\t\t\t   กีกีกีกีกีกีกีกีกีกีกีกีกีกีกีกีกี
		ก  กกก     กีกีกกกกกกกกกกกกกกกกกกกกกกกกกกกีกี
กกกกกกกกกกกกกกกก           กีกีกกกกกกฑจกกกกน๚กกกกหยกกกกกกกีกี
		 กกกก      กีกีกกกกกกกกกกกกกกกกกกกกกกกกกกกีกี
             กกกกกกกก      กีกีกีกีกีกีกีกีกีกีกีกีกีกีกีกีกี\n" NOR
]));
	set("exits", ([ 
	  "northdown" : __DIR__"qingshijie",
	  "west" : __DIR__"baoguosi",
]));

	set("coor/x",-180);
  set("coor/y",-120);
   set("coor/z",10);
   setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "west" && is_wanted(me))
		return 0;
	return :: valid_leave(me, dir);
}
