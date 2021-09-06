// ������Ǯ���������ı�SJ����״�����󲿷�ԭ������Snowman dazao ϵͳ 
#include <ansi.h>
string s_good(int i)
{
	switch(i){
		case 10..90:	return "�ޱ�";	
		case 9:		return "�ޱ�";	
		case 8:		return "����";	
		case 7:		return "����";	
		case 6:		return "��Ϊ";	
		case 5:		return "�൱";	
		case 4:		return "ʮ��";	
		case 3:		return "�ǳ�";	
		case 2:		return "�Ƚ�";	
		case 1:		return "����";	
		case -1:	return "����ô";	
		case -2:	return "�ܲ�";	
		case -3:	return "����";	
		default:	return "һ��";	
	}
}

string s_power(int i)
{
	if( i >= 300 )	return HIR"�������"NOR;
	if( i >= 280 )	return HIR"��Ԫ����"NOR;	
	if( i >= 250 )	return HIR"������˫"NOR;	
	if( i >= 220 )	return HIM"��������"NOR;	
	if( i >= 200 )	return HIY"������ƥ"NOR;
	if( i >= 180 )	return HIG"��������"NOR;
	if( i >= 160 )	return HIB"��������"NOR;
	if( i >= 140 )	return HIC"ն����ħ"NOR;
	if( i >= 120 )	return RED"�����ױ�"NOR;
	if( i >= 100 )	return MAG"�������"NOR;
	if( i >= 80 )	return YEL"�ܸ�"NOR;
	if( i >= 60 )	return GRN"ˮ׼����"NOR;
	if( i >= 40 )	return BLU"����"NOR;
	if( i >	20 )	return CYN"��С"NOR;
	if( i <= 0 )	return "����";
	if( i <= -20 )	return "����";
	return "һ��";
}

inherit EQUIP;
#include <mudlib.h>
#define PRICE 50 //�����������۵ļ۸���

int weapon_setup(mapping mp);

void create()
{
	//set_name("����", ({ "chang jian","sword","jian" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		//set("value", 200);
		set("material", "steel");
		set("wield_msg", "$N�ó�$n�������С�\n");
		set("unwield_msg", "$N�������е�$n��\n");
		set("wield_maxneili", 100);
		set("wield_neili", 10);
		set("wield_str", 20);		
	}
	set("flag", 4);
	set("verbs", ({ "slash", "hack", "slice", "thrust" }) );
	set("weapon_prop/damage", 1);
	set("skill_type", "sword");
	set("weapon_mp",
([ /* sizeof() == 29 */
  "weight" : 8934,
  "weapon_prop/strength" : 8,
  "wield_msg" : "
$N��һ��$n������������С�
",
  "b_id" : "zhang",
  "weapon_prop/constitution" : 8,
  "value" : 306000,
  "long" : "",
  "weapon_prop/neili" : 534,
  "verbs" : ({ /* sizeof() == 3 */
      "bash",
      "crush",
      "slam"
    }),
  "sharpness" : 2,
  "weapon_prop/damage" : 50,
  "weapon_prop/intelligence" : 8,
  "rigidity" : 2,
  "name_st" : ({ /* sizeof() == 2 */
      "���������;���",
      "�����������"
    }),
  "skill_type" : "staff",
  "unwield_msg" : "
$N�����е�$n�Ż��������ҡ�
",
  "weapon_prop/jingli" : 927,
  "flag" : 16,
  "name" : "[1;32m����[1;31m��а��[0;0m",
  "no_sell" : 1,
  "id" : ({ /* sizeof() == 4 */
      "pixie staff",
      "pixie",
      "zhang",
      "staff"
    }),
  "imbued" : 3,
  "material" : "greatsteel",
  "wield_maxneili" : 3610,
  "unit" : "��",
  "wield_neili" : 826,
  "weapon_prop/dexerity" : 8,
  "basic_name" : "[1;31m��а",
  "wield_str" : 24,
])
);
	set_name(query("weapon_mp")["name"], query("weapon_mp")["id"]);
	/*if (INTERMUD_MUD_NAME != "SJ")
	set("value",(query("weapon_mp")["value"]* PRICE ) > 15000000 ? 15000000 : query("weapon_mp")["value"] * PRICE );
	else
	set("value",(query("weapon_mp")["value"]* 2 ) > 15000000 ? 15000000 : query("weapon_mp")["value"] * 2 );
	*/
	//ΪʲôҪ�������ע�ͣ�
	set("value",(query("weapon_mp")["value"]* PRICE ) > 15000000 ? 15000000 : query("weapon_mp")["value"] * PRICE );

	//set("value",query("weapon_mp")["value"]* PRICE );
	//�趨value�����ֵ���ٶ�Ҫ�����
	weapon_setup(query("weapon_mp"));
	setup();
}

int weapon_setup(mapping mp)
{
	string *vb;
	int i;
	mapping w_mp;
	string str = "";
	int p;
	int w;
	string st;
	
	
	if( !clonep(this_object()) )
		return 0;
	if( !mapp(mp) ) return 0;
	
	vb = keys(mp);
	
	for( i = 0; i < sizeof(vb); i++ )
		set(vb[i], mp[vb[i]]);
	
	set_name(mp["name"], mp["id"]);
	set_weight(mp["weight"]);
	set("actions", (: call_other, WEAPON_D, "query_action" :) );
	
	w_mp = query("weapon_mp");	
	
	
	if( stringp(w_mp["long2"]) )
		str = w_mp["long2"];
	str += "����һ"+w_mp["unit"]+"��" + s_good(w_mp["rigidity"]) + "��Ӳ��";

	switch(w_mp["material"]){
		case "xuantie":	str += BLU"����"NOR; break;
		case "supersteel": str += "��������"; break;
		case "greatsteel": str += "������"; break;
		case "softsteel": str += "����"; break;
		case "bamboo": str += "����"; break;
		case "wood": str += "̴ľ"; break;
		default: str +=	"����";	break;
	}
	w = w_mp["weight"];
	str +=	"�Ƴɣ���"+sprintf("%s", chinese_number(w/500)+"��"+chinese_number((w%500)/50)+"��"+chinese_number((w%50)/5)+"Ǯ")+"��"+w_mp["name"]+"��\n";

	//mm = w_mp;
	if( intp( w_mp["weapon_prop/damage"] ) )
		p = w_mp["weapon_prop/damage"];
	else if( intp(w_mp["weapon_prop"]["damage"]) )
		p = w_mp["weapon_prop"]["damage"];
	else p = 0;
	
	str += "������"	+ ( w_mp["flag"]==4?s_good(w_mp["sharpness"])+"������":"" ) + "����"+ s_power(p) + "��������\n";
	str += "��������������֣���"
		+ chinese_number(w_mp["wield_str"]) + "��"
		+ chinese_number(w_mp["wield_maxneili"]) + "��"
		+ chinese_number(w_mp["wield_neili"]) +	"��\n";

	if( w_mp["name_st"] ){
		if( stringp(w_mp["name_st"]) )
			str += "�Լ�һ�Ź�׭�֡� "HIG +	w_mp["name_st"]	+ NOR" ��\n\n";
		else if( sizeof(w_mp["name_st"]) > 0	){
			st = implode(w_mp["name_st"][0..<1], "��");
			str += "�Լ�һ�Ź�׭�֡� "HIG +	st + NOR" ��\n\n";
		}
	}
	set("long",str);
	delete("imbued");
	//�۸���Ե�������
	
	return 1;
}

int move(mixed dest, int silently)
{
			
	return ::move(dest, silently);
}

int weapon_fix()
{	
	delete("weapon_mp/broken");
	delete("broken");	
}
