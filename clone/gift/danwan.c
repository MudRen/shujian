//����ϵͳ֮����Ǳ����������ƪ

#include <ansi.h>

inherit ITEM;

string long();

void create()
{
        
        string str;        
        switch(random(4)) {
                        case 0: str = "max_neili";      break;
                        case 1: str = "combat_exp";     break;
                        case 2: str = "max_jingli";     break;
                        case 3: str = "potential";      break;
                }
        set_name(WHT "��ҩ" NOR, ({ "dan yao","yao" }));        
        if (clonep())
                set_default_object(__FILE__);
        else {
              if ( stringp(str) ) {
                set("bonus", str);
                }
                set_weight(300);
                set("long", (: long :));
                set("unit", "��");
                set("no_sell", "��ô�õĶ�����Ҳ�������");
                //set("no_drop", 1);
                //set("no_give", 1);
                set("cloned",0);
                set("value", 2000);
        }
        setup();
}

void init()
{
        object me = this_player();
        int i, size;
        string name, id, id1;
        string *first_name=({HIR+"��",YEL+"��",HIY+"��",HIG+"��",HIC+"��",HIB+"��",MAG+"��",HIY+"��",HIW+"��",WHT+"��",HIM+"��",CYN+"��"});
        string *first_id=({"chi","cheng","huang","lv","qing","lan","zi","jin","yin","yu","xian","fei"});
        string *second_name=({"ˮ","��","ʯ","��","ɰ","��","��","��","��","��"});
        string *second_id=({"shui","zhu","shi","ji","sha","lin","long","hu","bao","feng"});
        string *third_name=({"��"+NOR,"��"+NOR});
        string *third_id=({"wan", "dan"});
	if (!query("cloned"))
	{
        size = sizeof(first_name);
        i = random(size);
        name = first_name[i];
        id = first_id[i];

        size = sizeof(second_name);
        i = random(size);
        name += second_name[i];
        id += second_id[i];

        size = sizeof(third_name);
        i = random(size);
        name += third_name[i];
        id1 = third_id[i];
        
        if ( query("secret_obj") ) 
                set_name(HIY + "��Ʒ" + name, ({id+" "+id1,id,id1}));
        else
                set_name(name, ({id+" "+id1,id,id1}));
        
        if((me->query("gender") == "����" && random(100) == 1) || random(500) == 1)
        {
        	set_name("��������ɢ",({"mizong longyangsan","san"}));
        	set("bonus","recover_jj");
        	delete("secret_obj");
        	set("gift_target",getuid(me));//���ɽ���
        }//

        if ( environment() == me ) {
                add_action("do_eat", "fu");
                add_action("do_eat", "eat");
        }
        set("cloned",1);
	}
                add_action("do_eat", "fu");
                add_action("do_eat", "eat");

        /*if ( ! query("secret_obj")) return;

        if ( query("gift_target") == getuid(me) )
                return;

        ob = find_player(query("gift_target"));

        if ( ! ob) return;

        if ( ob->query_temp("die_by_from") == me){
                ob->delete_temp("die_by_from");
                CHANNEL_D->do_channel( this_object(), "rumor",sprintf("%sŪ����һ��%s��", me->name(1), query("name")));
                set("gift_target", getuid(me));
                set("eat_time", uptime());
        }
        return;
        */
        

}

string long()
{
        string str;
        
        str = query("name")+"("+capitalize(query("id"))+")\n";
        str += "һ��"+query("name")+"������(fu)�Ժ���";
        if ( query("secret_obj") ) 
                str += "����";
        switch(query("bonus")) {
                case "combat_exp":      str +="����ʵս����";   break;
                case "max_jingli":      str +="��߾���";       break;
                case "max_neili":       str +="�Ӵ�����";       break;
                case "potential":       str +="����Ǳ��";       break;
                case "recover_jj":      str +="�ָ�����֮��";     break;
                default:                str +="һ��";           break;
        }
        str += "�Ĺ�Ч��\n";
        if (query("bonus")=="recover_jj")
        	str += HIG"\n����������ҩ����˵����֮�������������������а��������ô�������������ָܻ�����֮��֮��\n"NOR;
        
        return str;
}

int do_eat(string arg)
{
        object me = this_player();
        int i, max;
        string str;

        if (!id(arg)) return 0;

        if ( me->is_busy() || me->is_fighting()) 
                return notify_fail("����æ���ء�\n");

       // if ( query("gift_target") != getuid(me))
              //  return notify_fail("���ʲô�ط��õ��ģ�\n");

        str = HIW"$N����һ��"+query("name")+HIW"����ʱ���û���Ϊ֮һ��������";
        switch(query("bonus")) {
                case "combat_exp":
                        if ( query("secret_obj") )
                                i = 4000 + random(2000);
                        else
                                i = 500 + random(80);
                        me->add("combat_exp", i);
                        log_file("job/PRIZE", 
                                sprintf("%8s%-10sʳ��%6s���õ�%4d�㾭�顣",
                                        ctime(time())[4..19],
                                        me->name(1)+"("+getuid(me)+")",
                                        query("name"),
                                        i
                                ), me
                        );
                        str += chinese_number(i)+"��ʵս���顣\n"NOR;
                        break;
                case "max_jingli":
                        if ( query("secret_obj") )
                                i = random(40) + 30;
                        else
                                i = random(20) + 10;
                        me->add("max_jingli", i);
                        me->add("eff_jingli", i);
                        str += chinese_number(i)+"���������\n"NOR;
                        break;
                case "max_neili":
                        if ( query("secret_obj") )
                                i = random(40) + 30;
                        else
                                i = random(20) + 10;
                        max = (me->query_skill("force")-me->query_temp("apply/force")) * 8 + me->query("combat_exp") / 1000;
                        if ( (me->query("max_neili") - 100 ) < max )
                                me->add("max_neili", i);
                        str += chinese_number(i)+"�����������\n"NOR;
                        break;
                case "potential":
                        if ( query("secret_obj") )
                                i = 500 + random(100);
                        else
                                i = random(50) + 300;
                        me->add("potential", i);
/*
                        if ( me->query("potential") > me->query("max_pot"))
                                me->set("potential", me->query("max_pot"));
*/
                        str += chinese_number(i)+"��Ǳ�ܡ�\n"NOR;
                        break;
                case "recover_jj":
                	if (me->query("gender")!="����" )
                	{
                		message_vision("$N͵͵������һ��ҩ���ƵĶ�������һ�¡�\n",me);
                		tell_object(me,HIR"��������������ƻ�ȫ�������ĸо�����\n"NOR);
                		me->unconcious();
                		return 1;//��dest 
                	}
                	me->set("gender","����");
                	if (me->query("class") == "eunuch")
                		me->delete("class");
                	if (me->query_skill("pixie-jian",1)){               		
                		tell_object(me,HIR"�����л�����������а�����ĵ��εΣ����ھ���Ҫ������\n"NOR);				
				log_file("static/ABANDON", sprintf("%s(%s) ��ҩ������ȫ�� %d �� %s �� %s\n",
				me->name(1), me->query("id"), me->query_skill("pixie-jian",1), to_chinese("pixie-jian") , ctime(time()) ));				                		
                		me->delete_skill("pixie-jian");
                	}
                	str = HIW"$N����һ��"+query("name")+HIW"����ʱ���û���Ϊ֮һ��";
                	str += "�ָ�������֮��\n";
                	log_file("job/PRIZE", 
                                sprintf("%8s%-10sʳ��%6s���ָ���JJ��",
                                        ctime(time())[4..19],
                                        me->name(1)+"("+getuid(me)+")",
                                        query("name"),                                        
                                ), me
                        );
                        break;
                default :
                        return notify_fail("�����⣬�������Ա�㱨��\n");
        }
        message_vision(str, me);
        "/adm/daemons/emoted"->do_emote(me,"taste");
        if ( query("secret_obj"))
                CHANNEL_D->do_channel( this_object(), "rumor",sprintf("���˿���%s������һ��%s��", me->name(1), query("name")));
        destruct(this_object());
        return 1;
}
