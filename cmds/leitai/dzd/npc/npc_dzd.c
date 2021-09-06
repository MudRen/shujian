#include <ansi.h>
inherit NPC;

void create()
{
        set_name("������", ({ "bingqi jia" }) );
        set("gender", "����" );
        set_temp("apply/long", ({"����һ��ר�������Ÿ�����Ʒ�ļ��ӡ�
������Լ�ϲ������Ʒ ( na <��Ʒ����> )��\n"}));
          set("age", 14);       
        set("str", 30);
        set("dex", 25);
        set("con", 25);
        set("int", 30);            
        set("attitude", "friendly");
        set_temp("apply/id", ({ "jia" }));
        set_temp("apply/short", ({HIW"������"NOR"(Jia)"}));
        setup();
}

void init()
{
	add_action("do_get",({"��","na"}));
}

int do_get(string arg)
{
  	object me,ob;
  	me=this_player();
  	
  	if( !arg )return notify_fail("�����ʽ: na <��Ʒ����> ��\n");

    	switch (arg){
          	case "sword":                
          	case "jian": 	ob=new(BINGQI_D("changjian")); break;   
          	case "blade":               
          	case "dao": 	ob=new(BINGQI_D("blade")); break;   
          	case "whip":                
          	case "bian":	ob=new(BINGQI_D("whip")); break;         
          	case "ling":	ob=new(BINGQI_D("tieling")); break;
          	case "zhang":                  
          	case "staff":   ob=new(BINGQI_D("gangzhang")); break;
          	case "zhen":
          	case "needle":	ob=new(BINGQI_D("xiuhua")); break;
          	case "gun":                 
          	case "club":	ob=new(BINGQI_D("tiegun")); break;           
            case "xiao":    ob=new(BINGQI_D("yuxiao")); break;           
          	case "hammer":
          	case "chui":	ob=new(BINGQI_D("falun1")); break;
          	case "bang":
          	case "stick":	ob=new(BINGQI_D("zhubang")); break;
          	case "gou": 
          	case "hook":    ob=new(BINGQI_D("hook")); break; 
          	case "armor": 
          	case "jia":     ob=new(ARMOR_D("armor")); break;
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
                ob=new(BINGQI_D("tiebi"));break;

          	case "fire": 
          	case "huo":     ob=new(MISC_D("fire")); break;
              case "fen":     ob=new("/d/xingxiu/obj/yao3"); break;
          	default :	return notify_fail("û�����ֶ�����\n");
        }
        
       	if(!ob) return 0;
       	ob->delete("value");
       	if(ob->query("weapon_prop/damage"))
          	ob->set("weapon_prop/damage", 50);
	if(ob->query("armor_prop/armor"))
          	ob->set("armor_prop/armor", 70);
       	ob->move(me);
       	ob->set("dzd_obj",1);
       	message_vision("$N����Ʒ�����ó�һ"+ob->query("unit")+"$n��\n",me, ob);  
       	return 1;
}

