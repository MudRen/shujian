
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW "��Ʒ��" NOR, ({ "wupin jia", "jia" }) );         
        set_weight(30000000);
        if( clonep() )
                set_default_object(__FILE__);
        else{
        set("unit", "��");
        set("long", "����һ��ר�������Ÿ�����Ʒ�ļ��ӡ�
������Լ�ϲ������Ʒ ( na <��Ʒ����> from jia )��
�����У�
    ��(dao, blade)��       ��(bian, whip)��
    ��(jian, sword)��      ��(gun, club)��
    ��(zhen, needle)��     ��(zhang, staff)��
    ��(ling)��             ��(bang, stick)��
    ����(jia, armor)��     ��(chui, hammer)��
    ��(gou, hook)��        ��(fu)��
    ����(fire)��           ����(fen)��
    ��(lun)��              ʯ��(shi)��
    ��(bi,brush)��

\n");
        set("material","wood");
        set("no_get",1);
        }
        setup();
}
void init()
{
    add_action("do_get",({"��","na"}));
}

int do_get(string arg)
{
  object me,ob;
  string arg1,arg2;
  me=this_player();
  if(!arg || sscanf(arg, "%s from %s", arg1, arg2)!=2)
         return notify_fail("�����ʽ: na <��Ʒ����> from jia��\n");
  if (arg2!="jia")
     return notify_fail("�����ʽ: na <��Ʒ����> from jia��\n");
    switch (arg1){
          case "sword":                
          case "jian":
                ob=new(BINGQI_D("changjian")); break;   
          case "blade":               
          case "dao":
                ob=new(BINGQI_D("blade")); break;   
          case "whip":                
          case "bian":
                ob=new(BINGQI_D("whip")); break;         
          case "ling":
                ob=new(BINGQI_D("tieling")); break;
          case "zhang":                  
          case "staff":   
                ob=new(BINGQI_D("gangzhang")); break;
          case "zhen":
          case "needle":
                ob=new(BINGQI_D("xiuhua")); break;
          case "gun":                 
          case "club":
                ob=new(BINGQI_D("tiegun")); break;           
          case "hammer":
          case "chui":
                ob=new(BINGQI_D("falun1")); break;
          case "bang":
          case "stick":
                ob=new(BINGQI_D("zhubang")); break; 
          case "armor": 
          case "jia":              
                ob=new(ARMOR_D("armor")); break;
          case "fire": 
          case "huo":              
                ob=new(MISC_D("fire")); break;
          case "fen":             
                ob=new("/d/xingxiu/obj/yao"); break;
          case "fu" :
                ob=new(BINGQI_D("dafu"));break;
          case "gou":
          case "hook":
                ob=new(BINGQI_D("hook"));break;
          case "lun":
                ob=new(BINGQI_D("falun1"));break;
          case "shi":
                ob=new(BINGQI_D("feihuangshi"));break;
          case "bi":
          case "brush":
                ob=new("/d/tiezhang/obj/tiebi");break;

          default :
                 return notify_fail("û�����ֶ�����\n");
                }
       if(!ob) return 0;
       ob->delete("value");
       if(ob->query("weapon_prop/damage"))
          ob->set("weapon_prop/damage", 50);
       ob->move(me);
       message_vision("$N����Ʒ�����ó�һ"+ob->query("unit")+"$n��\n",me, ob);  
       return 1;
}
