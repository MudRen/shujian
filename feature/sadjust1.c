// Modified by mxzhao 2004/02/18

#include <ansi.h>
inherit F_CLEAN_UP;
#include <mudlib.h>

string query(string name)
{
	if (name == "channel_id") return "��������";
	return 0;
}

void skill_adjust(object ob)
 {
 	mapping skl, maps;
 	string *sname,arg;
 	int i,lmt, death; 	
       int zs_attack, zs_damage, zs_armor,total;
	
	int st=ob->query("str"), intt=ob->query("int"), co=ob->query("con"), de=ob->query("dex");
	int ka=ob->query("kar"), pe=ob->query("per"), pu=ob->query("pur");

	if (ob != this_player()) return;
	// bbb �����̬д�� web ע�������һ������
	ob->delete("max_naili");
	lmt = st+intt+co+de;
/*            if (!wiz_level(ob) && (lmt>84 || st>31 || intt>31 || co>31 || de>31 || ka>30 || pe>30 || pu>30))
		CHANNEL_D->do_channel(this_object(), "wiz",
			sprintf("%s(%s)�츳��������=%d ��=%d ��=%d ��=%d ��=%d ��=%d ��=%d ͷ�����=%d",
                                ob->name(1), capitalize(ob->query("id")), st, intt, co, de, ka, pe, pu, lmt));
*/
	lmt = (int)ob->query("combat_exp");
	if (lmt < 0) lmt = 0;
	if (ob->query("shen") > lmt) ob->set("shen", lmt);
	if (ob->query("shen") < -lmt) ob->set("shen", -lmt);
	if (ob->query("reputation") > lmt) ob->set("reputation", lmt);
	for (i = to_int(pow(10.0 * lmt, 0.3333333));to_int(i*i/10.0*i)<=lmt;i++);
	lmt = i;
	ob->set("max_pot", 100 + lmt);
	if (ob->query("potential") > ob->query("max_pot")){
	
		ob->add("qn_balance",ob->query("potential")-ob->query("max_pot")); //�Զ��洢������
	tell_object(ob, sprintf("��Я����Ǳ�ܳ������ޣ�ϵͳ�Զ������洢��Ǳ�����У����Ǳ������������%d�㡣\n",
					ob->query("potential")-ob->query("max_pot")));
			ob->set("potential", ob->query("max_pot"));
	
	}

	// skills & exp ���	YUJ@SJ 2002-01-18
	skl = ob->query_skills();
	if (sizeof(skl)) {
		sname = keys(skl);
		foreach (string item in sname) {
			if (!intp(skl[item]) || skl[item] < 0) ob->delete_skill(item);
			else if (( SKILL_D(item)->type() == "martial" || SKILL_D(item)->type2() == "worker" ) && skl[item]> lmt) {
				tell_object(ob, sprintf("���ھ������ƣ���ġ�%s����%s��������%s����\n",
					to_chinese(item), chinese_number(skl[item]), chinese_number(lmt)));
				skl[item] = lmt;
				ob->improve_skill(item, (lmt+1)*(lmt+1), 1);
			}
		}
		switch (ob->query("family/family_name")) {
			case "������":
				if (skl["xuantian-wuji"] > 400 ) {
					ob->add("max_jing", (skl["art"]/2-40)*(skl["xuantian-wuji"]/15));
					ob->add("max_qi", (skl["art"]/2-30)*(skl["xuantian-wuji"]/12));
					break;
				}
				if (skl["art"] > 81) {
					ob->add("max_jing", (skl["art"]/2-40)*(skl["xuantian-wuji"]/15));
					ob->add("max_qi", (skl["art"]/2-30)*(skl["xuantian-wuji"]/15));
				}
				break;
			case "������":
			case "������":
				if (skl["buddhism"] > 61)
					ob->add("max_jing",(skl["buddhism"]/2-30)*(skl["force"]/10));
				if (skl["buddhism"] > 101)
					ob->add("max_qi",(skl["buddhism"]/2-40)*(skl["force"]/20));
				break;
			case "���ư�":
				if (skl["tiezhang-xinfa"] > 61 ){
					ob->add("max_qi", (skl["tiezhang-xinfa"]/2-30)*(skl["guiyuan-tunafa"]/20));
					ob->add("max_jing", (skl["tiezhang-xinfa"]/2-40)*(skl["guiyuan-tunafa"]/20));
				}
			case "������":
				if (skl["dacheng-fofa"] > 61)
					ob->add("max_jing",(skl["dacheng-fofa"]/2-30)*(skl["linji-zhuang"]/10));
				if (skl["dacheng-fofa"] > 101)
					ob->add("max_qi",(skl["dacheng-fofa"]/2-40)*(skl["linji-zhuang"]/20));
				break;
			case "�һ���":
				if (skl["qimen-bagua"] > 61){
					ob->add("max_qi", (skl["qimen-bagua"]/2-30)*(skl["bihai-chaosheng"]/15));
					ob->add("max_jing", (skl["qimen-bagua"]/2-30)*(skl["bihai-chaosheng"]/15));
				}
				break;
			case "�䵱��":
				if (skl["taoism"] > 61)
                                        ob->add("max_qi",(skl["taoism"]/2-20)*(skl["yinyun-ziqi"]/10));
				if (skl["taoism"] > 121)
					ob->add("max_jing",(skl["taoism"]/2-50)*(skl["yinyun-ziqi"]/25));
				break;
			case "ȫ���":
				if (skl["taoism"] > 61)
					ob->add("max_qi",(skl["taoism"]/2-30)*(skl["xiantian-gong"]/10));
				if (skl["taoism"] > 121)
					ob->add("max_jing",(skl["taoism"]/2-50)*(skl["xiantian-gong"]/25));
				break;
				
                                         case "��ң��":
				if (skl["art"] > 61)
					ob->add("max_qi",(skl["art"]/2-20)*(skl["beiming-shengong"]/10));
				if (skl["art"] > 121)
					ob->add("max_jing",(skl["art"]/2-50)*(skl["beiming-shengong"]/20));
				break;
                                         case "���չ�":
				if (skl["yangyanshu"] > 61)
					ob->add("max_qi",(skl["yangyanshu"]/2-20)*(skl["bahuang-gong"]/10));
				if (skl["yangyanshu"] > 121)
{                                        ob->add("max_jing",(skl["yangyanshu"]/2-50)*(skl["bahuang-gong"]/20));
}
				break;
			case "������":
				if (skl["poison"] > 61)
					ob->add("max_qi",(skl["poison"]/2-25)*(skl["huagong-dafa"]/10));
				if (skl["poison"] > 121)
					ob->add("max_jing",(skl["poison"]/2-50)*(skl["huagong-dafa"]/20));
				break;
			case "����Ľ��":
			case "����":
				if (skl["force"] > 81)
					ob->add("max_qi",(skl["force"]/2-40)*15);
				if (skl["force"] > 151)
					ob->add("max_jing",(skl["force"]/2-40)*15);
				break;
			case "ؤ��":
				death = ob->query("death_times");
                                if ( death > 400 ) death = 400;
				if ( death > 1){
					ob->add("max_qi", death * ob->query("con"));
					ob->add("max_jing", death * ob->query("con"));
				}
				if (skl["begging"] > 61)
					ob->add("max_qi",(skl["begging"]/2-30)*(skl["huntian-qigong"]/20));
				break;
			case "������":
				if (skl["huanxi-chan"] > 61)
					ob->add("max_jing",(skl["huanxi-chan"]/2-30)*(skl["longxiang-boruo"]/10));
				if (skl["huanxi-chan"] > 121)
					ob->add("max_qi",(skl["huanxi-chan"]/2-50)*(skl["longxiang-boruo"]/40));
				break;
			case "��Ĺ��":
				if (skl["yunu-xinjing"] > 81)
					ob->add("max_qi",(skl["yunu-xinjing"]/2-40)*10);
				if (skl["yunu-xinjing"] > 81)
					ob->add("max_jing",(skl["yunu-xinjing"]/2-40)*15);
				break;
			case "������":
                                                        if (skl["shenlong-yaoli"] > 81 && skl["dulong-dafa"] > 81){
		   			ob->add("max_qi", (skl["shenlong-yaoli"]/2-35)*(skl["dulong-dafa"]/16));
					ob->add("max_jing", (skl["shenlong-yaoli"]/2-35)*(skl["dulong-dafa"]/25));
	   			}
				break;
			case "��ɽ��":
				if (skl["songshan-jian"] > 51)
					ob->add("max_qi", skl["songshan-jian"]*3);
				if (skl["hanbing-zhenqi"] > 81)
					ob->add("max_jing",(skl["hanbing-zhenqi"]/2-40)*10);
				break;
			case "��ɽ��":
				if (skl["zhengqi-jue"] > 61 ){
                                                                      ob->add("max_qi", (skl["zhengqi-jue"]/2-30)*(skl["force"]/20));
                                                                      ob->add("max_jing", (skl["zhengqi-jue"]/2-30)*(skl["force"]/20));
				}
				break;
			default:
				if( skl["hamagong"] ){
					ob->add("max_qi", skl["hamagong"] * 5);
					ob->add("max_jing", skl["hamagong"] * 5);
				}
				if( skl["tianmo-gong"] ){
					ob->add("max_qi", skl["tianmo-gong"] * 5);
					ob->add("max_jing", skl["tianmo-gong"] * 5);
				}
				if (skl["beauty"] > 61 ){
                                                                      ob->add("max_qi", (skl["beauty"]/2-30)*(skl["force"]/30));
                                                                      ob->add("max_jing", (skl["beauty"]/2-30)*(skl["force"]/20));
				}
		}
	}

/*

// ����ʱЧ��

        

        if( ob->query("relife/gifts/total") >0 && !ob->query_temp("gift_add_buff") )

        {
        total = ob->query("relife/gifts/total",1);
        zs_attack= total *2+random(12);
        zs_damage= total *2 +random(12);
        zs_armor = total *2+random(12);
        ob->add_temp("apply/attack",zs_attack);
        ob->add_temp("apply/damage",zs_damage);
        ob->add_temp("apply/armor",zs_armor);
 ob->set_temp("gift_add_buff",1);
        tell_object(ob,
sprintf(BLINK+HBRED"�������������򵽵��츳ʹ��������ˡ�%s���������ʣ���%s���㹥��������%s�����������"NOR"\n\n",
chinese_number(zs_attack), chinese_number(zs_damage),chinese_number(zs_armor)));
      
        }

*/

if(ob->query("on_hook"))
	{
		
 ob->delete_temp("block_msg");
 ob->start_busy(999);

		
  if(ob->query("on_hook/time")-time()>0) {
    
    tell_object(ob,HIG"\n\n��Ŀǰ���ڱչ�Ǳ���У�Ԥ�ƻ�������"+ CHINESE_D->chinese_time(ob->query("on_hook/time")-time())+ "��\n"NOR);
    tell_object(ob, HIG"�����Ҫ����Ǳ�ޣ���ֱ�ӹر�MUD���ڡ�\n");
    tell_object(ob, HIG"�����Ҫȡ��Ǳ�ޣ�������"HIR"onhook halt"HIG"ָ�\n\n\n"NOR);
    ob->apply_contion("onhook",(ob->query("on_hook/time")-time())/10+1);
                                        }
                                         
  if(ob->query("on_hook/time")-time()<=0) {
    tell_object(ob,HIG"\n\n��չ�Ǳ���Ѿ���"+ CHINESE_D->chinese_time(time()-ob->query("on_hook/time"))+ "ǰ������\n"NOR);
    arg = "over";
      "/cmds/usr/onhook"->main(ob,arg);
             }

		
	
	}
	
	// ����
	ob->add("max_qi", ob->query("max_neili") * ob->query("con") / 80);

	// enable ���	YUJ@SJ 2002-01-18
	if (!mapp(skl)) skl = ([]);
	maps = ob->query_skill_map();
	if (sizeof(maps)) {
		sname = keys(maps);
		foreach (string item in sname) {
			if (!stringp(maps[item])) continue;
			if (!skl[maps[item]] || !SKILL_D(maps[item])->valid_enable(item))
				ob->map_skill(item);
		}
	}
//      ����״̬��飬yuj@sj 1999-09-13
	if (stringp(ob->query("marry/id")))
	{
		object marry_ob = new(LOADUSER_OB, ob->query("marry/id"));
		if (marry_ob->restore())
		{
			if (marry_ob->query("marry/id") == ob->query("id"))
				ob->set("marry/name", marry_ob->query("name"));
			else
				ob->delete("marry");
		}
		else
			ob->delete("marry");
		if (!ob->query("marry"))
			ob->add("divorce", 1);
		destruct(marry_ob);
	}
	"/cmds/usr/top"->add_rank(ob);
}
