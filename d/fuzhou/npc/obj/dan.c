// By action@SJ ����ר��
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"Quest�ؼ�"NOR, ({ "yangjing dan","dan" }) );
        set_weight(10);
                set("unit", "��");
                set("long", "һ����������Quest������鼮��\n");
                set("no_drop", "�������صĶ�����ô������Ҷ��ء�\n");
                set("no_get", "�������������뿪�Ƕ���\n");
                set_weight(100);
	              set("value",3000000);
	              set("no_give",1);
	              set("treasure",1);
	              set("degree",1);
	              set("flag","spec/jiemi");
	              set("rest",0);
	              set("desc","һ����������Quest������鼮��");
	              set("credit",1000);

       setup();
}/*
void init()
{
        add_action("do_eat", "read");
}

int do_read(string arg)
{
	object me = this_player();
	
	if(arg!="miji")
             return notify_fail("��Ҫ����ʲô?\n");
       if (me->is_busy()) {return notify_fail("����æ���ء�\n");}
	if (!me->query("wizard/jiemi")<10)
	{
		tell_object(me, HIR"�����Quest�ؼ������ʼ���·𿴵�������ѡ��\n"NOR);
		tell_object(me, HIR"1��������Quest���ա�\n"NOR);
		tell_object(me, HIR"2��������Quest���ԡ�\n"NOR);
		tell_object(me, HIR"3����Ȫ��Quest���ա�\n"NOR);
		tell_object(me, HIR"4����󡹦Quest���ա�\n"NOR);
		tell_object(me, HIR"5���貨΢��Quest���ԡ�\n"NOR);
		tell_object(me, HIR"6����������Quest���ա�\n"NOR);
		tell_object(me, HIR"7�����һ���Quest���ա�\n"NOR);
		tell_object(me, HIR"8����Ѫ��צQuest���ա�\n"NOR);

		tell_object(me, HIR"����Ҫ�õ����ǣ�"NOR);
		input_to("get_gift", 1);
	}
	else
		tell_object(me, HIR"��Ļ��ᶼ�Ѿ�ʹ�ù���!\n"NOR);
	return 1;
}

void get_gift(string arg)
{
	object me = this_player();
	int select;
	string str;
	
	if (!sscanf(arg, "%d", select))
	{
		tell_object(me,HIR"��ֻ��ѡ��1-8�е�һ����������ѡ��"NOR);
		input_to("get_gift", 1);
		return;
	}
	switch (select)
	{
		case 1: if (me->query("quest/jiuyin1/pass"))
			{
				tell_object(me, HIC"���Ѿ�ѧ���˾������Ͼ�������ѡ��"NOR);
				input_to("get_gift", 1);
				return;
			}
                    if(me->query("id")=="action" ||(random(me->query("kar"))+random(me->query("int"))) > 50
	                && (random(me->query_dex(1))+random(me->query_int(1))) > 75
	                && random(me->query("kar"))>28){
                     	  tell_object(me,HIG"��ϲ,�������˾����񹦵��Ͼ�\n"NOR);
                              CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "��Ե�ɺ�֮��,��Ԫ����Ʒ��������" + HIW + "�������Ͼ�" + NOR + "��\n");
	                       me->set("quest/jiuyin1/pass",1);
                      }
			str = "��ʹ����һ�ν��Ի��ᡣ\n";
			break;
		case 2: if (me->query("quest/jiuyin2/pass"))
			{
				tell_object(me, HIC"���Ѿ�ѧ���˾������¾�������ѡ��"NOR);
				input_to("get_gift", 1);
				return;
			}
						
	              if(random(me->query_kar()) > 22){
                     	  tell_object(me,HIG"��ϲ,�������˾����񹦵��¾�\n"NOR);
                              CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "��Ե�ɺ�֮��,��Ԫ����Ʒ��������" + HIW + "�������¾�" + NOR + "��\n");
                              me->set("quest/jiuyin2/pass",1);
                     }
			str = "��ʹ����һ�ν��Ի��ᡣ\n";
			break;	
		case 3: if (me->query("quest/ѩɽ�ɺ�/�书/lengquanshengong"))
			{
				tell_object(me, HIC"���Ѿ�ѧ������Ȫ�񹦡�������ѡ��"NOR);
				input_to("get_gift", 1);
				return;
			}
                     if(me->query("id")=="action" ||(random(me->query("kar"))+random(me->query("int"))) > 50
                         && !random(3) //�������Ѷ�
                         && (random(me->query_con(1))+random(me->query_int(1))) > 75
                         && me->query("kar")<31)
                        {  
                   	         tell_object(me,HIG"��ϲ,����������Ȫ�񹦡�\n"NOR);
                              CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "��Ե�ɺ�֮��,��Ԫ����Ʒ��������" + HIW + "��Ȫ��" + NOR + "��\n");                                              
                              me->set("quest/ѩɽ�ɺ�/�书/lengquanshengong", 1);
                         }
			str = "��ʹ����һ�ν��Ի��ᡣ\n";
			break;	
		case 4: if (me->query("oyf/son")&&me->query("oyf/hamagong"))
			{
				tell_object(me, HIC"���Ѿ�ѧ���˸�󡹦��������ѡ��"NOR);
				input_to("get_gift", 1);
				return;
			}
                     if(me->query("id")=="action" ||(random(me->query("pur"))+random(me->query("kar"))+random(me->query("con"))) > 85
                         && me->query("con")>22)
                        {  
                   	         tell_object(me,HIG"��ϲ,�������˸�󡹦��\n"NOR);
                              CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "��Ե�ɺ�֮��,��Ԫ����Ʒ��������" + HIW + "��󡹦" + NOR + "��\n");                                              
                              me->set("oyf/hamagong", 1);
                              me->set("oyf/son",1);
                              me->set_skill("hamagong",10);
                         }
			str = "��ʹ����һ�ν��Ի��ᡣ\n";
			break;	
		case 5:  if(me->query("quest/�����˲�/�书/yuxiang") && me->query("quest/�����˲�/�书/pass"))
			{
				tell_object(me, HIC"���Ѿ�ѧ�����貨΢����������ѡ��"NOR);
				input_to("get_gift", 1);
				return;
			}
                       if(random(me->query("kar"))+random(me->query("int")) > 50
                       && (random(me->query_dex(1))+random(me->query_int(1))) > 75
                       && random(me->query("kar"))>28)
                     {                   	        
                              tell_object(me,HIG"��ϲ,���������貨΢����\n"NOR);
                              CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "��Ե�ɺ�֮��,��Ԫ����Ʒ��������" + HIW + "�貨΢��" + NOR + "��\n");                                              
                              me->set("quest/�����˲�/�书/yuxiang", 1);
                              me->set("quest/�����˲�/�书/pass",1);
                         }
			str = "��ʹ����һ�ν��Ի��ᡣ\n";
			break;	
		case 6: if (me->query("quest/pixie/pass"))
			{
				tell_object(me, HIC"���Ѿ�ѧ���˿������䡣������ѡ��"NOR);
				input_to("get_gift", 1);
				return;
			}
                     if(me->query("id")=="action" || me->query("gender")==("����")
		           && random(me->query_int(1)) > 30 
		           && random(me->query_dex(1)) > 35
		           && random(me->query_kar()) > 15 ) 
                        {  
                   	         tell_object(me,HIG"��ϲ,�������˿������䡣\n"NOR);
                              CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "��Ե�ɺ�֮��,��Ԫ����Ʒ��������" + HIW + "��������" + NOR + "��\n");                                              
                              me->set("quest/pixie/pass", 1);
                         }
			str = "��ʹ����һ�ν��Ի��ᡣ\n";
			break;	
		case 7: if (me->query("quest/hubo/pass")&&me->query("double_attack"))
			{
				tell_object(me, HIC"���Ѿ�ѧ�������һ�����������ѡ��"NOR);
				input_to("get_gift", 1);
				return;
			}
                     if(me->query("id")=="action" || me->query("pur")>27
                       && random(me->query("pur")) > 25 ) 
                        {  
                   	         tell_object(me,HIG"��ϲ,�����������һ�����\n"NOR);
                              CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "��Ե�ɺ�֮��,��Ԫ����Ʒ��������" + HIW + "���һ���" + NOR + "��\n");                                              
                              me->set("quest/hubo/pass", 1);
                              me->set("double_attack",1);
                         }
			str = "��ʹ����һ�ν��Ի��ᡣ\n";
			break;	
		case 8: if (me->query("quest/ningxue/pass"))
			{
				tell_object(me, HIC"���Ѿ�ѧ������Ѫ��צ��������ѡ��"NOR);
				input_to("get_gift", 1);
				return;
			}
                     if(me->query("id")=="action" || random(me->query_con(1)) > 35 
                        	&& random(me->query_dex(1)) > 35
                            && random(me->query("kar")) > 25 ) {
                   	         tell_object(me,HIG"��ϲ,����������Ѫ��צ��\n"NOR);
                              CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "��Ե�ɺ�֮��,��Ԫ����Ʒ��������" + HIW + "��Ѫ��צ" + NOR + "��\n");                                              
                              me->set("quest/ningxue/pass", 1);
                         }
			str = "��ʹ����һ�ν��Ի��ᡣ\n";
			break;	

		default:tell_object(me,HIR"��ֻ��ѡ��1-8�е�һ����������ѡ��"NOR);
			input_to("get_gift", 1);
			return;
	}
	tell_object(me, HIR"���Ѿ���Quest�����ؼ���\n"NOR);
	tell_object(me, HIR + str + NOR);
	destruct(this_object());
	return;
}

*/
