// By action@SJ ����ר��
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"��ӹȫ��"NOR, ({ "book","quanji" }) );
        set_weight(10);
                set("unit", "��");
                set("long", "һ��������鼮����˵Ԥʾ�������������ĩ�յ����١�\n");
 //               set("no_drop", "�������صĶ�����ô������Ҷ��ء�\n");
                set("no_get", "�������������뿪�Ƕ���\n");
                set_weight(100);
	              set("value",3000000);
	              set("no_give",1);
	              set("treasure",1);
	              set("degree",1);
	              set("flag","spec/jiemi");
	              set("rest",1);
	              set("desc",HIR"ĩ������"NOR);
	              set("credit",1);

       setup();
}



void init()
{
        add_action("do_eat", "read");
}


int do_eat(string arg)
{
	object me = this_player();
	
	if(arg!="book")
             return notify_fail("��Ҫ����ʲô?\n");
       if (me->is_busy()) {return notify_fail("����æ���ء�\n");}
	if (!me->query("wizard/jiemi"))
	{
		tell_object(me, HIR"ĩ�ռ������٣������ѡ�����¼��ּ������ȹ����µ�ʱ�⣺\n"NOR);
		tell_object(me, HIR"1�������Ͼ�\n"NOR);
		tell_object(me, HIR"2�������¾�\n"NOR);
		tell_object(me, HIR"3����Ȫ�񹦡�\n"NOR);
		tell_object(me, HIR"4����󡹦��\n"NOR);
		tell_object(me, HIR"5���貨΢����\n"NOR);
		tell_object(me, HIR"6���������䡣\n"NOR);
		tell_object(me, HIR"7�����һ�����\n"NOR);
		tell_object(me, HIR"8����Ѫ��צ��\n"NOR);

		tell_object(me, HIR"����Ҫ�õ����ǣ�"NOR);
		input_to("get_gift", 1);
	}
	else
		tell_object(me, HIR"��Ļ����Ѿ�ʹ�ù���!\n"NOR);
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
                   
                     	  tell_object(me,HIG"��ϲ,��ѧ���˾����񹦵��Ͼ�\n"NOR);
                              CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "��Ե�ɺ�֮��,ѧ����" + HIW + "�������Ͼ�" + NOR + "��\n");
	                       me->set("quest/jiuyin1/pass",1);
                      
			str = "�úñ��ذɣ�Ӣ�ۡ��ڴ����������ټ���\n";
			break;
			
		case 2: if (me->query("quest/jiuyin2/pass"))
			{
				tell_object(me, HIC"���Ѿ�ѧ���˾������¾�������ѡ��"NOR);
				input_to("get_gift", 1);
				return;
			}
						
	             
                     	  tell_object(me,HIG"��ϲ,��ѧ���˾����񹦵��¾�\n"NOR);
                              CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "��Ե�ɺ�֮��,ѧ����" + HIW + "�������¾�" + NOR + "��\n");
                              me->set("quest/jiuyin2/pass",1);
                     
			str = "�úñ��ذɣ�Ӣ�ۡ��ڴ����������ټ���\n";
			break;	
			
		case 3: if (me->query("quest/ѩɽ�ɺ�/�书/lengquanshengong"))
			{
				tell_object(me, HIC"���Ѿ�ѧ������Ȫ�񹦡�������ѡ��"NOR);
				input_to("get_gift", 1);
				return;
			}
                    
                   	         tell_object(me,HIG"��ϲ,��ѧ������Ȫ�񹦡�\n"NOR);
                              CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "��Ե�ɺ�֮��,ѧ����" + HIW + "��Ȫ��" + NOR + "��\n");                                              
                              me->set("quest/ѩɽ�ɺ�/�书/lengquanshengong", 1);
                   
       str = "�úñ��ذɣ�Ӣ�ۡ��ڴ����������ټ���\n";
       break;	
		
		case 4: if (me->query("oyf/son")&&me->query("oyf/hamagong"))
			{
				tell_object(me, HIC"���Ѿ�ѧ���˸�󡹦��������ѡ��"NOR);
				input_to("get_gift", 1);
				return;
			}
                 
                 
                   	         tell_object(me,HIG"��ϲ,��ѧ���˸�󡹦��\n"NOR);
                               CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "��Ե�ɺ�֮��,ѧ����" + HIW + "��󡹦" + NOR + "��\n");                                               
                              me->set("oyf/hamagong", 1);
                              me->set("oyf/son",1);
                              me->set_skill("hamagong",10);
                     
       
       str = "�úñ��ذɣ�Ӣ�ۡ��ڴ����������ټ���\n";
       break;	
       
		case 5:  if(me->query("quest/�����˲�/�书/yuxiang") && me->query("quest/�����˲�/�书/pass"))
			{
				tell_object(me, HIC"���Ѿ�ѧ�����貨΢����������ѡ��"NOR);
				input_to("get_gift", 1);
				return;
			}
                                       	        
                              tell_object(me,HIG"��ϲ,��ѧ�����貨΢����\n"NOR);
                              CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "��Ե�ɺ�֮��,ѧ����" + HIW + "�貨΢��" + NOR + "��\n");                                              
                              me->set("quest/�����˲�/�书/yuxiang", 1);
                              me->set("quest/�����˲�/�书/pass",1);
                        
       str = "�úñ��ذɣ�Ӣ�ۡ��ڴ����������ټ���\n";
       break;	
       
		case 6: if (me->query("quest/pixie/pass"))
			{
				tell_object(me, HIC"���Ѿ�ѧ���˿������䡣������ѡ��"NOR);
				input_to("get_gift", 1);
				return;
			}
              
                   	         tell_object(me,HIG"��ϲ,��ѧ���˿������䡣\n"NOR);
                              CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "��Ե�ɺ�֮��,ѧ����" + HIW + "��������" + NOR + "��\n");                                              
                              me->set("quest/pixie/pass", 1);
                     
       str = "�úñ��ذɣ�Ӣ�ۡ��ڴ����������ټ���\n";
       break;	
       
		case 7: if (me->query("quest/hubo/pass")&&me->query("double_attack"))
			{
				tell_object(me, HIC"���Ѿ�ѧ�������һ�����������ѡ��"NOR);
				input_to("get_gift", 1);
				return;
			}
                 tell_object(me,HIG"��ϲ,��ѧ�������һ�����\n"NOR);
                              CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "��Ե�ɺ�֮��,ѧ����" + HIW + "���һ���" + NOR + "��\n");                                              
                              me->set("quest/hubo/pass", 1);
                              me->set("double_attack",1);
                        
       str = "�úñ��ذɣ�Ӣ�ۡ��ڴ����������ټ���\n";
       break;	
		case 8: if (me->query("quest/ningxue/pass"))
			{
				tell_object(me, HIC"���Ѿ�ѧ������Ѫ��צ��������ѡ��"NOR);
				input_to("get_gift", 1);
				return;
			}
                
                   	         tell_object(me,HIG"��ϲ,��ѧ������Ѫ��צ��\n"NOR);
                              CHANNEL_D->do_channel(this_object(), "rumor",me->name(1) + "��Ե�ɺ�֮��,ѧ����" + HIW + "��Ѫ��צ" + NOR + "��\n");                                              
                              me->set("quest/ningxue/pass", 1);
       str = "�úñ��ذɣ�Ӣ�ۡ��ڴ����������ټ���\n";
       break;	
       
       
		default:tell_object(me,HIR"��ֻ��ѡ��1-8�е�һ����������ѡ��"NOR);
			input_to("get_gift", 1);
			return;
	}
	
	
	
	me->set("wizard/jiemi",1);
	tell_object(me, HIR"���Ѿ�ѡ���ĩ���ռ������ˡ�\n"NOR);
	tell_object(me, HIR + str + NOR);
	destruct(this_object());
	return;
}

