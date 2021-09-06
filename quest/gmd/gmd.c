#include <ansi.h>
inherit ROOM;
void create()
{ 
       set("short",HIR"光明顶"NOR);
       set("long", "
    这里就是明教光明顶。你走到这里就可看见三个鲜红色大字。明教，少林，\n"+
"丐帮中明教是最大的教，少林是最大的门派，而丐帮则是最大帮派。明教自由\n"+
"波斯总教传至中原已有百多年的历史了。明教始终都以反元抗胡，行善去恶及\n"+
"除暴安良为自已的宗旨。但由于明教太大，门下教众难免莨莠不齐，至使被名\n"+
"门正派称为魔教。正中央一面红色火焰的大旗上书：\n"+
"\n\n"HIR"\t\t\t光    明    顶\n\n"NOR);
      
        set("outdoors", "明教光明顶");
  set("exits", ([
                
                "east" :  __DIR__"houtu1",
               
        ]));
   setup();        
       
}
//是镜像
int is_mirror() { return 1; }