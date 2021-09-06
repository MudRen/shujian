#include <ansi.h>
inherit NPC;
#define ZHAOQIN_DIR "/d/tanggu/"
//�ļ�Ŀ¼
#define BIWU_LEITAI ZHAOQIN_DIR"biwuleitai.c"
//������̨

void create()
{
        set_name(HIR"��̨������"NOR, ({ "leitai fuzeren","leitai ren","ren"  }) );
        set("gender", "����" );
        set_temp("apply/long", ({YEL"\n����һ��ר�ŷ��Ÿ�����Ʒ�ĸ����ˡ�
����������õ��Լ�ϲ������Ʒ ( na <��Ʒ����> )��

"NOR+CYN"��(dao, blade)   ��(bian, whip)   ��(jian, sword)  
��ɱذ��(dagger) ��(zhujian)    ���(zhubang)
��(gun, club)    ��(zhen, needle) ��(zhang, staff)
��(ling)         ��(bang, stick)  ����(jia, armor) 
��(chui, hammer) ��(gou, hook)    ��(fu)
��(lun)          ʯ��(shi)        ��(bi,brush)  
��(xiao)         ����(fire)       ����(fen)"NOR}));
        set("age", 20);  
        set("per", 30);       
        set("str", 30);
        set("dex", 25);
        set("con", 25);
        set("int", 30);  
        set_temp("leitai", 1);           
        set("attitude", "friendly");
        setup();
}

void init()
{
	if(this_player()->query_temp("quest/bwzh/leitai"))
    		add_action("do_get",({"��","na"}));
}
string prefix, str;

int move(mixed dest, int silently)
{
	if (::move(dest, silently)) {
		str = environment()->query("dest_room");
		prefix = WHT "��"+environment()->query("short")+WHT "��"NOR;
		return 1;
	}
	return 0;
}
object room;
string buf = "", color = NOR;

void relay_message(string msgclass, string msg)
{
	string *ary;
	string tmp, tmp1, tmp2;

	if (msgclass[0..5] == "wizard") return;
	buf += msg;
	buf = replace_string(buf, "\r\n", "\n");
	ary = explode("\n"+buf, "\n");
	if (sizeof(ary) && buf[<1..<1] != "\n") {
		buf = ary[<1];
		ary = ary[0..<2];
	} else buf = "";

	if (!room) room = load_object(str);
	if (sizeof(ary)) foreach (tmp in ary) {
		message("vision", prefix+color+tmp+NOR"\n", room);
		while (sscanf(tmp, "%s"CSI"%sm%s", tmp1, color, tmp2) == 3)
			tmp = tmp1 + tmp2;
		if (color[0] != 27) color = CSI+color+"m";
	}
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
          case "zhubang":
                ob=new(BINGQI_D("zhubang"));break;
          case "zhujian":
                ob=new(BINGQI_D("zhujian"));break;
          case "dagger":
                ob=new(BINGQI_D("dagger"));break;
          	case "fire": 
          	case "huo":     ob=new(MISC_D("fire")); break;
          	case "fen":     ob=new("/d/xingxiu/obj/yao"); break;
          	default :	return notify_fail("û�����ֶ�����\n");
        }
        
       	if(!ob) return 0;
       	ob->delete("value");
       	if(ob->query("weapon_prop/damage"))
          	ob->set("weapon_prop/damage", 50);
       	ob->move(me);
       	message_vision("$N��"+this_object()->query("name")+"����ӹ�һ"+ob->query("unit")+"$n��\n",me, ob);  
       	return 1;
}

