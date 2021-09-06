//add by tangfeng
//2005.3
mapping get_poison(string poison);
void destruct_poison(object me);
mapping *poi_list = ({
	(["id":	 "snake_poison", // ���ж���E������
	  "name":       "�߶�", // ���ж�����������
	  "col":	""BLU"", // �ж���������ɫ
	  "con":	"տ��֮��",]), // �ж�������״̬
	(["id":	 "xx_poison",
	  "name":       "�����ƶ�",
	  "col":	""BLU"",
	  "con":	"տ��֮��",]),
	(["id":	 "xuanmin_poison",
	  "name":       "��ڤ�ƶ�",
	  "col":	""HIW"",
	  "con":	"˪��֮��",]),
	(["id":	 "dsy_poison",
	  "name":       "���ڴ���ӡ�ƶ�",
	  "col":	""CYN"",
	  "con":	"����",]),
	(["id":	 "fs_poison",
	  "name":       "��ʬ��",
	  "col":	""HIG"",
	  "con":	"����",]),
	(["id":	 "huagu_poison",
	  "name":       "�������ƾ綾",
	  "col":	""BLU"",
	  "con":	"տ��֮��",]),
	(["id":	 "man_poison",
	  "name":       "�����ܻ���",
	  "col":	""HIB"",
	  "con":	"����",]),
	(["id":	 "qinghua_poison",
	  "name":       "�黨��",
	  "col":	""MAG"",
	  "con":	"����",]),
	(["id":	 "qishang_poison",
	  "name":       "����ȭ��",
	  "col":	""HIR"",
	  "con":	"����֮��",]),
	(["id":	 "qzhu_poison",
	  "name":       "ǧ�����ֶ�",
	  "col":	""HIR"",
	  "con":	"����֮��",]),
	(["id":	 "sl_poison",
	  "name":       "������",
	  "col":	""BLU"",
	  "con":	"տ��֮��",]),
	(["id":	 "sy_poison",
	  "name":       "����ӡ�ƶ�",
	  "col":	""HIR"",
	  "con":	"����֮��",]),
	(["id":	 "warm_poison",
	  "name":       "�ȶ�",
	  "col":	""RED"",
	  "con":	"���֮��",]),
	(["id":	 "hot_poison",
	  "name":       "��",
	  "col":	""HIR"",
	  "con":	"����֮��",]),
	(["id":	 "cold_poison",
	  "name":       "����",
	  "col":	""HIC"",
	  "con":	"����֮��",]),
	(["id":	 "bing_poison",
	  "name":       "�������붾",
	  "col":	""HIB"",
	  "con":	"տ��֮��",]),
	(["id":	 "bt_poison",
	  "name":       "���߶�",
	  "col":	""YEL"",
	  "con":	"����֮��",]),
	(["id":	 "hb_poison",
	  "name":       "�������ƶ�",
	  "col":	""HIB"",
	  "con":	"տ��֮��",]),
});
mapping get_poison(string poison)
{
	int i;
	for(i=0;i<sizeof(poi_list);i++)
	{
	      if(poi_list[i]["id"]==poison)
	      		return poi_list[i];
	}
	return (["id":	 poison,
	  	"name":       "�綾",
	  	"col":	""GRN"",
	  	"con":	"����",]);
}
void destruct_poison(object me)
{
	mapping conditions,my_poison;
 	string *names,name;
 	int lvl=0;
	int i;
	if(mapp(conditions = me->query_conditions_by_type("poison")))
	{
		names = keys(conditions);
		for(i=0;i<sizeof(conditions);i++)
		{
			if(conditions[names[i]]>lvl)
				lvl = conditions[names[i]];
			name  = names[i];
			my_poison = get_poison(name);
			my_poison["lvl"] = lvl;
			if(random(2)) message_vision(HIW"\nͻȻһ�����������$N��$N����֮"NOR+my_poison["col"]+my_poison["name"]+HIW"��Ȼ��ȫ��ʧ�ˣ�\n"NOR, me);
			else message_vision(HIW"\n$N��ɫ��Щ"+my_poison["con"]+"���ƺ�����"NOR+my_poison["col"]+my_poison["name"]+HIW"��һ��������֣�$Nȫ���ָ��ˣ�\n"NOR, me);
			me->apply_condition(my_poison["id"], -1);
		}
	}
	me->clear_condition();//��ʵ�����ȫ��ȥ��du��
}
