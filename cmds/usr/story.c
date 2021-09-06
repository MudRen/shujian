//tangfeng@SJ 
//story��¼
//add ���Ǿ� by tangfeng 2004/11/1
//add ���Ӣ�۴� by redhat@Sjmud 2009/4/8

#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me);
string get_string(string str);

//feihu
string quest_feihu(object me); 
string feihu_skill(object me);
//tlbb
string quest_tlbb(object me); 
string tlbb_skill(object me); 
//lchj
string quest_lchj(object me); 
string lchj_skill(object me); 
//shediao
string quest_shediao(object me); 
string shediao_skill(object me); 


int main(object me, string arg)
{
	object ob;
	string arg1,arg2,str;
	int i_all=0,i_feihu=0,i_tlbb=0,i_lchj=0,i_shediao=0;

	str="\n";
	if (!arg)
	{
		ob = me;
		i_all=1;
	}
	else if (sscanf(arg, "%s form %s", arg1,arg2)) 
	{     
		switch (arg1)
		{
		case "feihu" : i_feihu=1;break;
		case "tlbb"  : i_tlbb=1;break;
		case "lchj"  : i_lchj=1;break;//���Ǿ�
		case "shediao"  : i_shediao=1;break;//���Ӣ�۴�
		default :
			return notify_fail("Ŀǰֻ����ѩɽ�ɺ��������˲������Ǿ������Ӣ�۴�����ϸ��������İ�����\n");
		}
		if (wizardp(me))
		{
			ob = present(arg2, environment(me));
			if (!ob) ob = LOGIN_D->find_body(arg2);
			if (!ob) ob = find_living(arg2);
			if (!ob || !me->visible(ob)) return notify_fail("��Ҫ�쿴˭��״̬��\n");
		} 
		else
			return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
	}
	else
	{
        ob = me;
		switch (arg)
		{
		    case "feihu" : i_feihu=1;break;
		    case "tlbb"  : i_tlbb=1;break;
			case "lchj"  : i_lchj=1;break;//���Ǿ�
				case "shediao"  : i_shediao=1;break;//���Ӣ�۴�
			default :
				if (wizardp(me))
				{
					ob = present(arg, environment(me));
					if (!ob) ob = LOGIN_D->find_body(arg);
					if (!ob) ob = find_living(arg);
					if (!ob || !me->visible(ob)) return notify_fail("��Ҫ�쿴˭��״̬��\n");
					i_all=1;
				} 
				else
					return notify_fail("Ŀǰֻ����ѩɽ�ɺ��������˲������Ǿ������Ӣ�۴�����ϸ��������İ�����\n");
		}
	}


	if (!wizardp(me) && me->is_busy())
		return notify_fail("����æ���ء�\n");
	
	if(wizardp(me) && userp(ob)&& me!=ob)
	{
        str =   "������������������������������������������������������������\n";
		str +=get_string(YEL"�������ڲ�ѯ"+ob->query("name")+"�ļ�¼��"NOR);
	    tell_object(me,str);
	}

	if(i_all==1)  
	{
        str =  "������������������������������������������������������������\n";
	    str +=get_string(HIY"���齣����ȫ��¼��"NOR);
		str += "������������������������������������������������������������\n";
		if(ob->query("mana")||wizardp(me))
		{   
			str +=sprintf("%30s",HIG"������")+ob->query("name");
			str +="\n";
			str +=sprintf("%30s",HIG"������")+chinese_number(ob->query("mana"))+NOR;
			str +="\n";
		}
		if(wizardp(me) && me->query("id")=="tangfeng")
		{
			str +=sprintf("%30s",HIG"��Դ��")+chinese_number(ob->query_kar())+NOR;
			str +="\n";
			str +=sprintf("%30s",HIG"���ԣ�")+chinese_number(ob->query_int())+NOR;
			str +="\n";
		}
		str += quest_feihu(ob);
		str += quest_tlbb(ob);
		str += quest_lchj(ob);
		str += quest_shediao(ob);
	}
	else if(i_feihu==1)        
		str = quest_feihu(ob);
	else if(i_tlbb==1)
		str = quest_tlbb(ob);
	else if(i_lchj==1)
		str = quest_lchj(ob);
		else if(i_shediao==1)
		str = quest_shediao(ob);
	else return notify_fail("Ŀǰֻ����ѩɽ�ɺ��������˲������Ǿ�����ϸ��������İ�����\n");

    str +=   "������������������������������������������������������������\n";
	tell_object(me,str);
	return 1;
}

string quest_feihu(object me)
{
	string str= "\n";
	if(!me) return "BUG��\n";
	if(!me->query("quest/ѩɽ�ɺ�"))
	{
        str =    "������������������������������������������������������������\n";
	    str +=get_string(HIW"��Ŀǰ����ѩɽ�ɺ���û���κμ�¼��"NOR);
		return str;
	}

	str =   "������������������������������������������������������������\n";
	str +=get_string(HIW"��ѩɽ�ɺ���"NOR);
	str +=   "������������������������������������������������������������\n";
    if(me->query("quest/ѩɽ�ɺ�/time"))
	{
		if(!me->query("quest/ѩɽ�ɺ�/��ҩƪ/over") )
			str +=get_string(WHT"��Ϸ��¼ʱ��"+CHINESE_D->chinese_time(time()-me->query("quest/ѩɽ�ɺ�/time"))+"��"NOR);
		else str +=get_string(WHT"��Ϸ��¼ʱ�䣺"+CHINESE_D->chinese_date(me->query("quest/ѩɽ�ɺ�/time"),1)+"��"NOR);
	}
	if(me->query("quest/ѩɽ�ɺ�/combat_exp"))
	{
			if(!me->query("quest/ѩɽ�ɺ�/��ҩƪ/over") )
				str +=get_string(WHT"��Ϸ��¼����"+chinese_number(me->query("combat_exp")-me->query("quest/ѩɽ�ɺ�/combat_exp"))+"��"NOR);
			else str +=get_string(WHT"��Ϸ��¼���飺"+me->query("quest/ѩɽ�ɺ�/combat_exp")+"��"NOR);
			str +="\n";
	}
	if(!me->query("quest/ѩɽ�ɺ�/��ҳ����ƪ"))
	{
		str +=get_string(HBRED"��Ϸ��¼���ҡ��㻹��ҪŬ����"NOR);
		str +=feihu_skill(me);
		return str;
	}
	if(!me->query("quest/ѩɽ�ɺ�/��ҳ����ƪ/over"))
	{
		if(random(2)) str +=get_string(HBRED"��һ������ΰ�����쳽�һ�����ƺ��ҵ�����"NOR);
		else str +=get_string(HBRED"��һ��̽�������Ѱ��ʧ��������ҳ������"NOR);
		str +=feihu_skill(me);
		return str;
	}

	str +=get_string(YEL"���Ѿ�����������ƺ��ҵ��������һЩ������"NOR);
	
	if(!me->query("quest/ѩɽ�ɺ�/����ƪ"))
	{
		if(random(2)) str +=get_string(HBRED"���ֻ������ù�һЩ���£���һ��������١�"NOR);
		else          str +=get_string(HBRED"���������˷�����һ���������ׯ��"NOR);
		str +=feihu_skill(me);
		return str;
	}
	
	if(!me->query("quest/ѩɽ�ɺ�/����ƪ/over"))
	{
		if(random(2)) str +=get_string(HBRED"�����硢��֮�����ƺ��Ѿ����ˣ�ֻ�ǹ��������"NOR);
		else          str +=get_string(HBRED"���������Ѿ����ˣ�ֻ��������������������˷���"NOR);
		str +=feihu_skill(me);
		return str;
	}   
	str +=get_string(YEL"���Ѿ���ԭ�����˷�ͺ��һ�����࣬���һЩ������"NOR);
	
	if(!me->query("quest/ѩɽ�ɺ�/��ҩƪ"))
	{
		if(random(2)) str +=get_string(HBRED"������С�˰��㣬���˷��ж�����δ����"NOR);
		else          str +=get_string(HBRED"20��ǰ�ľ����Ѿ����ˣ�����֮˵Ҳ��һ����ᡣ"NOR);
		str +=feihu_skill(me);
		return str;
	}
	
	if(!me->query("quest/ѩɽ�ɺ�/��ҩƪ/over"))
	{
		if(random(2)) str +=get_string(HBRED"�����Ѿ����ˣ������˷��ж�����δ������һ����Ѱ�ҽ�ҩ��"NOR);
		else          str +=get_string(HBRED"20��ǰ�������Ѿ����ˣ�Ŀǰ�ؼ������Ѱ���������˷�Ľ�ҩ��"NOR);
		str +=feihu_skill(me);
		return str;
	}

	str +=get_string(YEL"�嶾�̣���ɹ����������ض�����Ǻ��ġ�"NOR);
	str +=get_string(YEL"ҩ���ȣ���ɹ������ƽ�ҩ�ɹ������һЩ������"NOR);
	
	if(!me->query("quest/ѩɽ�ɺ�/����"))
	{
		str +=get_string(HBRED"���Ѿ����ѩɽ�ɺ��Ļ�����ڣ�����漰��һ�����ء�"NOR);
		str +=feihu_skill(me);
		return str;
	}

	str +=   "������������������������������������������������������������\n";
	str +=get_string(HIB"���������ء�"NOR);
	str +=   "������������������������������������������������������������\n";
	if(me->query("quest/ѩɽ�ɺ�/����/time"))
		str +=get_string(WHT"Ѱ����¼ʱ�䣺"+CHINESE_D->chinese_date(me->query("quest/ѩɽ�ɺ�/����/time"),1)+"��"NOR);
	if(me->query("quest/ѩɽ�ɺ�/����/combat_exp"))
	{
		str +=get_string(WHT"Ѱ����¼���飺"+me->query("quest/ѩɽ�ɺ�/����/combat_exp")+"��"NOR);
		str +="\n";
	}
	if(!me->query("quest/ѩɽ�ɺ�/����/start"))
	{
		str +=get_string(HBRED"������Ѱ�Ҵ�˵�еĴ������ء�"NOR);
		str +=feihu_skill(me);
		return str;
	}

	str +=get_string(YEL"���Ѿ���ʼѰ�Ҵ�˵�еĴ������ء�"NOR);
	if(me->query("quest/ѩɽ�ɺ�/����/jinku"))
		str +=get_string(YEL"���Ѿ��Ӵ������ػ�ô����ĲƱ��������ƽ�ȵȡ�"NOR);
	if(me->query("quest/ѩɽ�ɺ�/����/yaoku"))
		str +=get_string(YEL"�㷢���˴���ҩ�⣬����ҩ��������������������ҩ��"NOR);
	if(me->query("quest/ѩɽ�ɺ�/����/bingqiku"))
		str +=get_string(YEL"���Ѿ��ھ������������ı�����"+chinese_number(me->query("quest/ѩɽ�ɺ�/����/bingqiku"))+"������"NOR);
	if(me->query("quest/ѩɽ�ɺ�/����/shuku"))
		str +=get_string(YEL"����鷿���ֵ�һ�����ң���������Ѱ�ҵ����������������ҩ��"NOR);
	if(me->query("quest/ѩɽ�ɺ�/�书/lengquanshengong"))
		str +=get_string(YEL"�㾹Ȼ��һ����ҩ���ҵ�һ��ֽ�ţ���������Ȫ���ؼ��ĵص㡣"NOR);
	else if(me->query("quest/ѩɽ�ɺ�/����/shuku")>=3)
		str +=get_string(YEL"���һ����ҩ���ҵ�һ���ƺ��������书��ֽ�ţ�Ŀǰֻ��δ��Ҫ�졣"NOR);
	str +=feihu_skill(me);
	return str;
}
string feihu_skill(object me)
{
	string str= "";
	if(!me) return "BUG��\n";
	if(me->query("quest/ѩɽ�ɺ�/��ҳ����ƪ/over"))
	{
        str =   "������������������������������������������������������������\n";
	    str +=get_string(HIC"���ɺ��书��"NOR);
        str +=   "������������������������������������������������������������\n";
		if(me->query("quest/ѩɽ�ɺ�/�书/time"))
			str +=get_string(WHT"�书��¼ʱ�䣺"+CHINESE_D->chinese_date(me->query("quest/ѩɽ�ɺ�/�书/time"),1)+"��"NOR);
		if(me->query("quest/ѩɽ�ɺ�/�书/combat_exp"))
		{
			str +=get_string(WHT"�书��¼���飺"+me->query("quest/ѩɽ�ɺ�/�书/combat_exp")+"��"NOR);
			str +="\n";
		}
		if(me->query("quest/ѩɽ�ɺ�/�书/fight_hu"))
		{
		   if(me->query("quest/ѩɽ�ɺ�/�书/win_hu"))
			   str +=get_string(HIC"�������쳽��й�"+chinese_number(me->query("quest/ѩɽ�ɺ�/�书/fight_hu"))+"�ν����������"+chinese_number(me->query("quest/ѩɽ�ɺ�/�书/win_hu"))+"��ʤ����"NOR);
		   else
			   str +=get_string(HIC"�������쳽��й�"+chinese_number(me->query("quest/ѩɽ�ɺ�/�书/fight_hu"))+"�ν�������ϧһ��Ҳû��ʤ����"NOR);
		}

		if(me->query("quest/ѩɽ�ɺ�/�书/hujiadaofa"))
		   str +=get_string(HBYEL"���Ѿ�ѧ���˺��ҵ��������ŵ�������Ľ�������������"NOR);
		else if(me->query("quest/ѩɽ�ɺ�/�书/hujiadaofa_fail")>=3 && me->query("registered")<3)
			str +=get_string(YEL"��ʧȥ��ѧϰ���ҵ����Ļ��ᣬ���������VIP���㽫����µĻ��ᡣ"NOR);
		else if(me->query("quest/ѩɽ�ɺ�/�书/hujiadaofa_fail") && me->query("quest/ѩɽ�ɺ�/�书/hujiadaofa_fail")<3 && me->query("registered")<3)
			str +=get_string(YEL"��ʧȥ��ѧϰ���ҵ�����"+chinese_number(me->query("quest/ѩɽ�ɺ�/�书/hujiadaofa_fail"))+"�λ��ᣬ���㻹��"+chinese_number(3-me->query("quest/ѩɽ�ɺ�/�书/hujiadaofa_fail"))+"���ᡣ"NOR);
		else if(me->query("quest/ѩɽ�ɺ�/�书/hujiadaofa_fail"))
			str +=get_string(YEL"��ʧȥ��ѧϰ���ҵ�����"+chinese_number(me->query("quest/ѩɽ�ɺ�/�书/hujiadaofa_fail"))+"�λ��ᣬ���㻹�����޻��ᡣ"NOR);
		else
			str +=get_string(HBRED"������ӵ��ѧϰ���ҵ����Ļ��ᡣ��������ʵ���ʱ����̺�쳡�"NOR);
       
	   if(me->query("quest/ѩɽ�ɺ�/��ҩƪ/over"))
	   {
		   if(me->query("quest/ѩɽ�ɺ�/�书/fight_miao"))
		   {
			   if(me->query("quest/ѩɽ�ɺ�/�书/win_miao"))
				   str +=get_string(HIC"���������˷���й�"+chinese_number(me->query("quest/ѩɽ�ɺ�/�书/fight_miao"))+"�ν����������"+chinese_number(me->query("quest/ѩɽ�ɺ�/�书/win_miao"))+"��ʤ����"NOR);
			   else str +=get_string(HIC"���������˷���й�"+chinese_number(me->query("quest/ѩɽ�ɺ�/�书/fight_miao"))+"�ν�������ϧһ��Ҳû��ʤ����"NOR);
		   }
		   if(me->query("quest/ѩɽ�ɺ�/�书/miaojiajianfa"))
			   str +=get_string(HBYEL"���Ѿ�ѧ������ҽ��������������Ž����������߽��������ܴ�"NOR);
		   else if(me->query("quest/ѩɽ�ɺ�/�书/miaojiajianfa_fail")>=3 && me->query("registered")<3)
			   str +=get_string(YEL"���˷���ѧϰ��ҽ����Ļ��ᣬ���������VIP���㽫����µĻ��ᡣ"NOR);
		   else if(me->query("quest/ѩɽ�ɺ�/�书/miaojiajianfa_fail") && me->query("quest/ѩɽ�ɺ�/�书/miaojiajianfa_fail")<3 && me->query("registered")<3)
			   str +=get_string(YEL"��ʧȥ��ѧϰ��ҽ�����"+chinese_number(me->query("quest/ѩɽ�ɺ�/�书/miaojiajianfa_fail"))+"�λ��ᣬ���㻹��"+chinese_number(3-me->query("quest/ѩɽ�ɺ�/�书/miaojiajianfa_fail"))+"���ᡣ"NOR);
		   else if(me->query("quest/ѩɽ�ɺ�/�书/miaojiajianfa_fail"))
			   str +=get_string(YEL"��ʧȥ��ѧϰ��ҽ�����"+chinese_number(me->query("quest/ѩɽ�ɺ�/�书/miaojiajianfa_fail"))+"�λ��ᣬ���㻹�����޻��ᡣ"NOR);
		   else str +=get_string(HBRED"������ӵ��ѧϰ��ҽ����Ļ��ᡣ��������ʵ���ʱ��������˷硣"NOR);

		   if(me->query("quest/ѩɽ�ɺ�/�书/lengquanshengong_teach"))
			   str +=get_string(HBYEL"���Ѿ������硢���ϴ������ܣ��������˷ﴦ������Ȫ�񹦡�"NOR);
		   else if(me->query("quest/ѩɽ�ɺ�/�书/lengquanshengong"))
			   str +=get_string(YEL"���ƺ�����Ҫ�����Ȫ�񹦵�������ᡣ"NOR);
		   else if(me->query("quest/ѩɽ�ɺ�/�书/shuku")<3 )
			   str +=get_string(YEL"�㻹��ѧϰ��Ȫ�񹦵Ļ��ᡣ�񹦾�˵�ڱ���֮�С�"NOR);
		   else if(me->query("quest/ѩɽ�ɺ�/�书/shuku")==3 )
			   str +=get_string(YEL"��������һ��ѧϰ��Ȫ�񹦵Ļ��ᡣ��ϧû�гɹ���"NOR);
		   else if(me->query("quest/ѩɽ�ɺ�/�书/shuku")>=4 && me->query("registered")>=3)
			   str +=get_string(YEL"������������ѧϰ��Ȫ�񹦵Ļ��ᡣ��ϧû�гɹ���"NOR);
	   }
	}
	return str;
}
string quest_lchj(object me)
{
	string str= "\n";
	if(!me) return "BUG��\n";
	if(!me->query("quest/���Ǿ�"))
	{
        str =    "������������������������������������������������������������\n";
	    str +=get_string(HIW"��Ŀǰ�������Ǿ���û���κμ�¼��"NOR);
		return str;
	}

    str =   "������������������������������������������������������������\n";
	str +=get_string(HIW"�����Ǿ���"NOR);
    str +=   "������������������������������������������������������������\n";

	if(me->query("quest/���Ǿ�/time"))
	{
		if(!me->query("quest/���Ǿ�/���̽��ƪ/over"))
			str +=get_string(WHT"��Ϸ��¼ʱ��"+CHINESE_D->chinese_time(time()-me->query("quest/���Ǿ�/time"))+"��"NOR);
		else str +=get_string(WHT"��Ϸ��¼ʱ�䣺"+CHINESE_D->chinese_date(me->query("quest/���Ǿ�/time"),1)+"��"NOR);
	}
	if(me->query("quest/���Ǿ�/combat_exp"))
	{
		if(!me->query("quest/���Ǿ�/���̽��ƪ/over") && !me->query("quest/���Ǿ�/���̽��ƪ/over"))
		{
			if(me->query("combat_exp")> me->query("quest/���Ǿ�/combat_exp"))
				str +=get_string(WHT"��Ϸ��¼����"+chinese_number(me->query("combat_exp")-me->query("quest/���Ǿ�/combat_exp"))+"��"NOR);
			else if(me->query("combat_exp")== me->query("quest/���Ǿ�/combat_exp"))
				str +=get_string(WHT"��Ϸ��¼�����û���κα仯��"NOR);
			else str +=get_string(WHT"��Ϸ��¼���鳬��Ŀǰ���飺"+chinese_number(me->query("quest/���Ǿ�/combat_exp")-me->query("combat_exp"))+"��"NOR);
		}
		else str +=get_string(WHT"�����Ϸ��¼���飺"+me->query("quest/���Ǿ�/combat_exp")+"��"NOR);
		str +="\n";
	}

	if(!me->query("quest/���Ǿ�/ѩ�ȼ���ƪ"))
	{
		str +=get_string(HBRED"������Ŭ����........"NOR);
		str +=lchj_skill(me);
		return str;
	}
    if(!me->query("quest/���Ǿ�/ѩ�ȼ���ƪ/over"))
	{
		if(random(2)) str +=get_string(HBRED"��ʾ�������ڲ��£�Ѱ��ѩ�ȵ��ơ�"NOR);
		else str +=get_string(HBRED"һ��ԩ����һ�����£�һ�ξ��棬һ�α��顣"NOR);
		str +=lchj_skill(me);
		return str;
	}

	str +=get_string(YEL"��Ӷ������ڲ��£�����ѩ�ȵ������ơ�"NOR);

	if(!me->query("quest/���Ǿ�/���̽��ƪ/over"))
	{		
		if(random(2)) str +=get_string(HBRED"��һ������̽��ݡ�Ҳ��������Զ����һ���ա�"NOR);
		else          str +=get_string(HBRED"���Ǵ�˵�еľ����书�����ǲƱ�������������Σ�"NOR);
		str +=lchj_skill(me);
		return str;
	}
	str +=get_string(YEL"����̽��ݣ��ҿ�����ԩ�飬Ҳ�����ʫѡ����"NOR);
	if(me->query("quest/���Ǿ�/���̽��ƪ/baozang"))
	{
			str +=get_string(YEL"�㷢�����Ǳ��أ����ӵ��ƴ���֪һ�С�"NOR);
			str +=get_string(YEL"��Ȼû������֮�ƣ�����л��ǻ�ò��־��齱����"NOR);
		  str +=lchj_skill(me);
		  return str;
	}
	str +=lchj_skill(me);
	return str;
}
string lchj_skill(object me)
{
	string str= "";
	if(!me) return "BUG��\n";
	if(me->query("quest/���Ǿ�/ѩ�ȼ���ƪ/start"))
	{
        str =   "������������������������������������������������������������\n";
	    str +=get_string(HIB"�������书��"NOR);
        str +=   "������������������������������������������������������������\n";
		if(me->query("quest/���Ǿ�/�书/time"))
			str +=get_string(WHT"�书��¼ʱ�䣺"+CHINESE_D->chinese_date(me->query("quest/���Ǿ�/�书/time"),1)+"��"NOR);
        if(me->query("quest/���Ǿ�/�书/combat_exp"))
		{
			str +=get_string(WHT"�书��¼���飺"+me->query("quest/���Ǿ�/�书/combat_exp")+"��"NOR);
			str +="\n";
		}
		if(me->query("quest/���Ǿ�/�书/shenzhao")>=2)
		{
		   str +=get_string(HBYEL"��Ӷ���ѧ�����վ������������ʹ�����վ�����"NOR);
		   str +=get_string(HBYEL"���ִӵ��ƴ����һЩ���飬�����վ����Ÿ����ε�����"NOR);
		}	
		else if(me->query("quest/���Ǿ�/�书/shenzhao")==1)
		{
		   str +=get_string(HBYEL"��Ӷ���ѧ�����վ������������ʹ�����վ�����"NOR);
		   if(me->query("quest/���Ǿ�/ѩ�ȼ���ƪ/over"))
		   {
			   if(me->query("quest/���Ǿ�/�书/shenzhao_fail2")>=3 && me->query("registered")<3)
			   {
				   str +=get_string(YEL"������ʧȥ�˴ӵ��ƴ�ѧϰ���վ����߲�ε�������ᡣ"NOR);
				   str +=get_string(YEL"��Ȼ����������VIP���㽫����µ�������ᡣ"NOR);
			   }
			   else if(me->query("quest/���Ǿ�/�书/shenzhao_fail2") && me->query("quest/���Ǿ�/�书/shenzhao_fail2") <3 && me->query("registered")<3)
				   str +=get_string(YEL"��ʧȥ�˵��ƴ��������վ���"+chinese_number(me->query("quest/���Ǿ�/�书/shenzhao_fail2"))+"�λ��ᣬ���㻹��"+chinese_number(3-me->query("quest/���Ǿ�/�书/shenzhao_fail2"))+"���ᡣ"NOR);
			   else if(me->query("quest/���Ǿ�/�书/shenzhao_fail2"))
				   str +=get_string(YEL"��ʧȥ�˵��ƴ��������վ���"+chinese_number(me->query("quest/���Ǿ�/�书/shenzhao_fail2"))+"�λ��ᣬ���㻹�����޻��ᡣ"NOR);
			   else str +=get_string(HBRED"������ӵ�дӵ��ƴ�������߲�����վ��Ļ��ᡣ��������ʵ���ʱ����̵��ơ�"NOR);
		   }
		} 
		else if(me->query("quest/���Ǿ�/�书/shenzhao_fail")>=3 && me->query("registered")<3)
			str +=get_string(YEL"��ʧȥ�Ӷ����������վ��Ļ��ᣬ���������VIP���㽫����µĻ��ᡣ"NOR);
		else if(me->query("quest/���Ǿ�/�书/shenzhao_fail") && me->query("quest/���Ǿ�/�书/shenzhao_fail")<3 && me->query("registered")<3)
			str +=get_string(YEL"��ʧȥ�Ӷ����������վ���"+chinese_number(me->query("quest/���Ǿ�/�书/shenzhao_fail"))+"�λ��ᣬ���㻹��"+chinese_number(3-me->query("quest/���Ǿ�/�书/shenzhao_fail"))+"���ᡣ"NOR);
		else if(me->query("quest/���Ǿ�/�书/shenzhao_fail"))
			str +=get_string(YEL"��ʧȥ�Ӷ����������վ���"+chinese_number(me->query("quest/���Ǿ�/�书/shenzhao_fail"))+"�λ��ᣬ���㻹�����޻��ᡣ"NOR);
		else str +=get_string(HBRED"������ӵ���������վ��Ļ��ᡣ��������ʵ���ʱ����̶��䡣"NOR);
        
		if(me->query("quest/���Ǿ�/ѩ�ȼ���ƪ/over"))
		{
			if(me->query("quest/���Ǿ�/�书/sword"))
				str +=get_string(HBYEL"��ӵ���ѧϰ����ʬ�����������������־�����"NOR);
			else if(me->query("quest/���Ǿ�/�书/sword_fail")>=3 && me->query("registered")<3)
			{
				str +=get_string(YEL"������ʧȥѧϰ�ӵ��ƴ���ʬ�����Ļ��ᡣ\n"NOR);
				str +=get_string(YEL"��Ȼ����������VIP���㽫����µ�������ᡣ"NOR);
			}
			else if(me->query("quest/���Ǿ�/�书/sword_fail") && me->query("quest/���Ǿ�/�书/sword_fail") <3 && me->query("registered")<3)
				str +=get_string(YEL"��ʧȥѧϰ��ʬ������"+chinese_number(me->query("quest/���Ǿ�/�书/sword_fail"))+"�λ��ᣬ���㻹��"+chinese_number(3-me->query("quest/���Ǿ�/�书/sword_fail"))+"���ᡣ"NOR);
			else if(me->query("quest/���Ǿ�/�书/sword_fail"))
				str +=get_string(YEL"��ʧȥѧϰ��ʬ������"+chinese_number(me->query("quest/���Ǿ�/�书/sword_fail"))+"�λ��ᣬ���㻹�����޻��ᡣ"NOR);
			else str +=get_string(HBRED"������ӵ��ѧϰ��ʬ�����Ļ��ᡣ��������ʵ���ʱ����̵��ơ�"NOR);
		}
	}
	return str;
}
string quest_tlbb(object me)
{
	string str= "\n";
	if(!me) return "BUG��\n";
	if(!me->query("quest/�����˲�"))
	{
        str =    "������������������������������������������������������������\n";
	    str +=get_string(HIW"��Ŀǰ���������˲���û���κμ�¼��"NOR);
		return str;
	}

    str =   "������������������������������������������������������������\n";
	str +=get_string(HIW"�������˲���"NOR);
    str +=   "������������������������������������������������������������\n";

	if(me->query("quest/�����˲�/time"))
	{
		if(!me->query("quest/�����˲�/��������ƪ/over") && !me->query("quest/�����˲�/���ɾ�Ԯƪ/over"))
			str +=get_string(WHT"��Ϸ��¼ʱ��"+CHINESE_D->chinese_time(time()-me->query("quest/�����˲�/time"))+"��"NOR);
		else str +=get_string(WHT"��Ϸ��¼ʱ�䣺"+CHINESE_D->chinese_date(me->query("quest/�����˲�/time"),1)+"��"NOR);
	}
	if(me->query("quest/�����˲�/combat_exp"))
	{
		if(!me->query("quest/�����˲�/��������ƪ/over") && !me->query("quest/�����˲�/���ɾ�Ԯƪ/over"))
		{
			if(me->query("combat_exp")> me->query("quest/�����˲�/combat_exp"))
				str +=get_string(WHT"��Ϸ��¼����"+chinese_number(me->query("combat_exp")-me->query("quest/�����˲�/combat_exp"))+"��"NOR);
			else if(me->query("combat_exp")== me->query("quest/�����˲�/combat_exp"))
				str +=get_string(WHT"��Ϸ��¼�����û���κα仯��"NOR);
			else str +=get_string(WHT"��Ϸ��¼���鳬��Ŀǰ���飺"+chinese_number(me->query("quest/�����˲�/combat_exp")-me->query("combat_exp"))+"��"NOR);
		}
		else str +=get_string(WHT"�����Ϸ��¼���飺"+me->query("quest/�����˲�/combat_exp")+"��"NOR);
		str +="\n";
	}

	if(!me->query("quest/�����˲�/�貨΢��ƪ"))
	{
		str +=get_string(HBRED"������Ŭ����........"NOR);
		str +=tlbb_skill(me);
		return str;
	}
    if(!me->query("quest/�����˲�/�貨΢��ƪ/over"))
	{
		if(!me->query("quest/�����˲�/�貨΢��ƪ/wuliangover"))
		{
			if(random(2)) str +=get_string(HBRED"���Ѱ�Ҷ�������˵������ɽ������̽���С�"NOR);
			else str +=get_string(HBRED"Ѱ��ʧ�ٵĶ����У�ע��������������貨΢���ͱ����񹦡�"NOR);
		}
		else
		{
			if(random(2)) str +=get_string(HBRED"������ɽ�����Ķ���ȴ���ٳֵ���ٹȡ�����̽���С�"NOR);
			else str +=get_string(HBRED"Ѱ��ʧ�ٵĶ����У�ע��С���и�����ء�"NOR);
		}
		return str;
	}

	str +=get_string(YEL"���Ѿ�����������ٹȾȻأ������һЩ������"NOR);

	if(!me->query("quest/�����˲�/����Ӫ��ƪ/over"))
	{		
		if(random(2)) str +=get_string(HBRED"��һ���������´�ս����ù�Ķ�����ǣ�����У���Ȼֻ��������æ��"NOR);
		else          str +=get_string(HBRED"���ĵ�һ�𷨸�ɮ���书Ҳ����ɲ⣬����ֹ����ֻ�����ˡ�"NOR);
		str +=tlbb_skill(me);
		return str;
	}

	str +=get_string(YEL"������ָ����ڵ��⣬�ȶ��������ģ������һЩ������"NOR);

	if(!me->query("quest/�����˲�/��������ƪ/over"))
	{
		if(random(2)) str +=get_string(HBRED"˭��С�ˣ�˭��Ӣ�ۣ���ԭ���£������������ܱ�����"NOR);
		else          str +=get_string(HBRED"���־��䣬����ׯ��ս����Ħ���Ż꣬��ʷ��������..."NOR);
		str +=tlbb_skill(me);
		return str;
	}
	str +=get_string(YEL"����ׯ������������ɹ������ֳ���"NOR);
	str +=get_string(YEL"��Ħ�£���ɹ��ҿ��±���������ܡ�"NOR);
	if(me->query("quest/�����˲�/��������ƪ/good"))
		str +=get_string(YEL"����ǳɹ�˵�������������������ò��ֽ�����"NOR);
	if(me->query("quest/�����˲�/��������ƪ/bad"))
		str +=get_string(YEL"����ǳɹ��˻��������������壬��ò��ֽ�����"NOR);

	if(me->query("quest/�����˲�/��������ƪ/start"))
	{
		if(!me->query("quest/�����˲�/��������ƪ/over"))
			str +=get_string(HBRED"Ϊ�������֣�����Ľ�ݣ������ϣ��Ͼ����ǵÿ�ȭͷ�ġ�"NOR);
		else 
			str +=get_string(YEL"��������ִ��Ⱥؤ������������ɮ���������֣�Ϊ���µ�һ��"NOR);
		str +=tlbb_skill(me);
		return str;
	}
	if(me->query("quest/�����˲�/���ɾ�Ԯƪ/start"))
	{
		if(!me->query("quest/�����˲�/���ɾ�Ԯƪ/over"))
			str +=get_string(HBRED"����Ϊ�������룬�Ĳ�ս�������˵�Ҫ�ȵġ�ֻ��Σ�����ء�"NOR);
		else 
			str +=get_string(YEL"����ʤ��ԭȺ�ۣ���Ǳ����ɣ��ɹ�Ӫ�����壬Ϊ������ܡ�"NOR);
		str +=tlbb_skill(me);
		return str;
	}
	str +=tlbb_skill(me);
	return str;
}
string tlbb_skill(object me)
{
	string str= "";
	if(!me) return "BUG��\n";
	if(me->query("quest/�����˲�/�书"))
	{
        str =   "������������������������������������������������������������\n";
	    str +=get_string(HIC"�������书��"NOR);
        str +=   "������������������������������������������������������������\n";
		if(me->query("quest/�����˲�/�书/time"))
			str +=get_string(WHT"���ѧϰ��¼ʱ�䣺"+CHINESE_D->chinese_date(me->query("quest/�����˲�/�书/time"),1)+"��"NOR);
        if(me->query("quest/�����˲�/�书/combat_exp"))
		{
			str +=get_string(WHT"���ѧϰ��¼���飺"+me->query("quest/�����˲�/�书/combat_exp")+"��"NOR);
			str +="\n";
		}
		if(me->query("quest/�����˲�/�书/yuxiang"))
		{            
			if(me->query("quest/�����˲�/�貨΢��ƪ/over"))
				str +=get_string(YEL"���ҵ�MM�����񣬲����һЩ��ʾ�����ü����貨΢���Ĳ���"NOR);
			else
				str +=get_string(YEL"���ҵ�MM�����񣬲����һЩ��ʾ��"NOR);
		}
		if(me->query("quest/�����˲�/��ڤ��/pass"))
			str +=get_string(HBYEL"������ɽ�������Ѿ�ѧ���˱�ڤ�񹦾�ѧ��"NOR);
		else if(me->query("quest/�����˲�/��ڤ��/fail")>=3 && me->query("registered")<3)
		{
			str +=get_string(YEL"�������˷���ѧϰ��ڤ�񹦵Ļ��ᡣ"NOR);
			str +=get_string(YEL"��Ȼ����������VIP���㽫����µ�������ᡣ"NOR);
		}
		else if(me->query("quest/�����˲�/��ڤ��/fail"))
		{
			str +=get_string(YEL"������ʧȥ��ѧϰ��ڤ�񹦵�"+chinese_number(me->query("quest/�����˲�/��ڤ��/fail"))+"�λ��ᡣ"NOR);
			str +=get_string(YEL"���㻹�л���ѧϰ���µĲ�����Դ��������»�á�"NOR);
		}
		else str +=get_string(HBRED"������ӵ��ѧϰ��ڤ�񹦵Ļ��ᡣ"NOR);
	
		if(me->query("quest/�����˲�/�书/pass"))
			str +=get_string(HBYEL"�������Ѿ�ѧ�����貨΢����"NOR);
		else if(me->query("quest/�����˲�/�书/fail")>=3 && me->query("registered")<3)
		{
			str +=get_string(YEL"�������˷���ѧϰ�貨΢���Ļ��ᡣ"NOR);
			str +=get_string(YEL"��Ȼ����������VIP���㽫����µ�������ᡣ"NOR);
		}
		else if(me->query("quest/�����˲�/�书/fail"))
		{
			str +=get_string(YEL"������ʧȥ��ѧϰ�貨΢����"+chinese_number(me->query("quest/�����˲�/�书/fail"))+"�λ��ᡣ"NOR);
			str +=get_string(YEL"���㻹�л���ѧϰ���µĲ�����Դ��������»�á�"NOR);
		}
		else str +=get_string(HBRED"������ӵ��ѧϰ�貨΢���Ļ��ᡣ"NOR);
	}
	if(me->query("quest/tonglao/quest"))
	{
		if(me->query("quest/tonglao/pass"))
			str +=get_string(YEL"����"+chinese_number(me->query("quest/tonglao/quest"))+"�μ�����ɽ�ƻ�ż����ɽͯ�ѣ���ѧ�������书��"NOR);
		else if(me->query("quest/tonglao/second"))
			str +=get_string(YEL"����"+chinese_number(me->query("quest/tonglao/quest"))+"�μ�����ɽ�ƻ�ż����ɽͯ�ѡ�"NOR); 
		else str +=get_string(YEL"����"+chinese_number(me->query("quest/tonglao/quest"))+"�μ�����ɽ�ƻ𣬵�ʲôҲû���֡�"NOR);
	}

	if(me->query("quest/�����˲�/�书/quanli"))
		str +=get_string(HBYEL"��������������򵽡���豹��桱���书���С�"NOR);
	return str;
}

string quest_shediao(object me)
{
	string str= "\n";
	if(!me) return "BUG��\n";
	if(!me->query("quest/���Ӣ�۴�"))
	{
        str =    "������������������������������������������������������������\n";
	    str +=get_string(HIW"��Ŀǰ�������Ӣ�۴���û���κμ�¼��"NOR);
		return str;
	}

    str =   "������������������������������������������������������������\n";
	str +=get_string(HIW"�����Ӣ�۴���"NOR);
    str +=   "������������������������������������������������������������\n";

	if(me->query("quest/���Ӣ�۴�/time"))
	{
		if(!me->query("quest/���Ӣ�۴�/��ѩ����/over") )
			str +=get_string(WHT"��Ϸ��¼ʱ��"+CHINESE_D->chinese_time(time()-me->query("quest/���Ӣ�۴�/time"))+"��"NOR);
		else str +=get_string(WHT"��Ϸ��¼ʱ�䣺"+CHINESE_D->chinese_date(me->query("quest/���Ӣ�۴�/time"),1)+"��"NOR);
	}
	if(me->query("quest/���Ӣ�۴�/combat_exp"))
	{
		if(!me->query("quest/���Ӣ�۴�/��ѩ����/over") )
		{
			if(me->query("combat_exp")> me->query("quest/���Ӣ�۴�/combat_exp"))
				str +=get_string(WHT"��Ϸ��¼����"+chinese_number(me->query("combat_exp")-me->query("quest/���Ӣ�۴�/combat_exp"))+"��"NOR);
			else if(me->query("combat_exp")== me->query("quest/���Ӣ�۴�/combat_exp"))
				str +=get_string(WHT"��Ϸ��¼�����û���κα仯��"NOR);
			else str +=get_string(WHT"��Ϸ��¼���鳬��Ŀǰ���飺"+chinese_number(me->query("quest/���Ӣ�۴�/combat_exp")-me->query("combat_exp"))+"��"NOR);
				str +=get_string(HIC"���Ѿ��ɹ����������ġ���Х����λ�����������һЩ������"NOR);
		}
		else str +=get_string(WHT"�����Ϸ��¼���飺"+me->query("quest/���Ӣ�۴�/combat_exp")+"��"NOR);
		str +="\n";
	}
	else
		{

}

	str +=shediao_skill(me);
	return str;
}

string shediao_skill(object me)
{
	string str= "";
	if(!me) return "BUG��\n";
	if(me->query("quest/���Ӣ�۴�/yangjiaqiang"))
	{
        str =   "������������������������������������������������������������\n";
	    str +=get_string(HIC"������书��"NOR);
        str +=   "������������������������������������������������������������\n";
		if(me->query("quest/���Ӣ�۴�/yangjiaqiang/time"))
			str +=get_string(WHT"���ѧϰ��¼ʱ�䣺"+CHINESE_D->chinese_date(me->query("quest/���Ӣ�۴�/yangjiaqiang/time"),1)+"��"NOR);
        if(me->query("quest/���Ӣ�۴�/yangjiaqiang/combat_exp"))
		{
			str +=get_string(WHT"���ѧϰ��¼���飺"+me->query("quest/���Ӣ�۴�/yangjiaqiang/combat_exp")+"��"NOR);
			str +="\n";
		}
		if(me->query("quest/���Ӣ�۴�/��ѩ����/over"))
		{            
				str +=get_string(YEL"��ɹ���Ԯ��Х�졢���������ң������һЩ������"NOR);
		}
		if(me->query("quest/���Ӣ�۴�/yangjiaqiang/pass"))
			str +=get_string(HBYEL"�������Ѿ�ѧ�������ǹ��"NOR);
		else if(me->query("quest/���Ӣ�۴�/yangjiaqiang/fail")>=3 && me->query("registered")<3)
		{
			str +=get_string(YEL"�������˷���ѧϰ���ǹ�Ļ��ᡣ"NOR);
			str +=get_string(YEL"��Ȼ����������VIP���㽫����µ�ѧϰ���ᡣ"NOR);
		}
		else if(me->query("quest/���Ӣ�۴�/yangjiaqiang/fail"))
		{
			str +=get_string(YEL"������ʧȥ��ѧϰ���ǹ��"+chinese_number(me->query("quest/���Ӣ�۴�/yangjiaqiang/fail"))+"�λ��ᡣ"NOR);
			str +=get_string(YEL"���㻹�л���ѧϰ�����ʵ���ʱ�����ȥѰ����������̡�"NOR);
		}
		else str +=get_string(HBRED"������ӵ��ѧϰ���ǹ�Ļ��ᡣ"NOR);
	}
	if(me->query("quest/jiuyin1/pass"))
		str +=get_string(HBYEL"����ܲ�ͨ��������������¾����澭�Ͼ�"NOR);
	if(me->query("quest/jiuyin2/pass"))
		str +=get_string(HBYEL"��ӳ����紦����˳������������澭�¾�"NOR);
	return str;
}
string get_string(string str)
{
     return sprintf("%|60s",str)+"\n";
}
int help(object me)
{
	write("
������������������������������������������������������������
             ָ���ʽ : "+YEL"story <......>"NOR"
������������������������������������������������������������
"HIW"���������������������˽���story�Ѿ��ҿ��ĳ̶ȡ���Ҳ����ʹ
���������õ�һ����һ������ʾ��"NOR"
������������������������������������������������������������"YEL"
                story  ������м�¼
          story feihu  ���ѩɽ�ɺ���¼
           story tlbb  ��������˲���¼
           story lchj  ������Ǿ���¼
         story <���>  ��ʦר�ò�ѯ����
 story ...<form ���>  ��ʦר�ò�ѯ����"NOR"
������������������������������������������������������������
          "HIC"Ŀǰֻ����ѩɽ�ɺ��������˲������Ǿ���"NOR"
������������������������������������������������������������
		  \n"NOR);
return 1;
}
