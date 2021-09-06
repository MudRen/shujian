// addvip.c 
// by LinuX@SJ 2004/02/18

#include <ansi.h>

#define VIP_FILE       "/data/vip"
#define NULL 0

inherit F_SAVE;

mapping *notes;
string query_save_file();
void list_viplist(object me, int num);
void search_viplist(object me, string arg, int flag);
void do_read(object me, int i);
int search_mail(string mail);
int search_player(string player,string site);


void create()
{
	seteuid(getuid());
	restore();
}

int main(object me, string arg)
{
	mapping note;
	string key;
	string player,mail;
	string site;
	string s;
	int num,renew,i,day;
	
	if (!arg) {
		list_viplist(me, 10);
		return 1;
	}
		
	if (sscanf(arg, "%d", num) == 1) {
		do_read(me,num);
		return 1;
	}
	
	if (sscanf(arg, "%s -p", key) == 1) {
		search_viplist(me,key,1);
		return 1;
	}
	
	if (sscanf(arg, "%s -m", key) == 1) {
		if (!stringp(key) || sscanf(key, "%*s@%*s.%*s") != 3) 
			return notify_fail("ÄúÒªËÑË÷µÄµç×ÓÓÊ¼şµØÖ·´íÎó¡£ \n");
		search_viplist(me,key,0);
		return 1;
	}
	
    	if (sscanf(arg, "%s", s) == 1) {
		if ( s == "all" ) {
			list_viplist(me,0);
			return 1;
		}
	}

	if (sscanf(arg, "%s %s %s %d", site, player, mail, day) == 4) {
		if (wiz_level(me)<4)
			return notify_fail("Ö»ÓĞarch²Å¿ÉÒÔ½«Íæ¼ÒÁĞÈëVIP×Ü¹ÜÀíÃûµ¥¡£ \n");
			
	   site = lower_case(site);
	   player = lower_case(player);
	    if ( site!="ln"&& site!="ln2" && site!="bx" && site!="ty" && site!="cq") 
           	 	return notify_fail("±ØĞëÊÇLN,LN2,BX,TY,CQÕâ¼¸¸öÕ¾µÄÍæ¼Ò!\n");
	    if (!stringp(mail) || sscanf(mail, "%*s@%*s.%*s") != 3) 
			return notify_fail("µç×ÓÓÊ¼şµØÖ·´íÎó¡£ \n");
		site = upper_case(site);
		i = search_mail(mail);
		if (i > 0) {
			write(" "+HIY+mail+NOR+" Õâ¸öĞÅÏäµØÖ·ÒÑ¾­ÓĞÈËÊ¹ÓÃÁË£¬±àºÅÎª£º" + HIW + i + NOR + " ¡£");
			search_viplist(me,mail,0);
			return 1;
		
		}
		i = search_player(player,site);
		if (i > 0) {
			write(" "+HIY+player+"@"+site+NOR+" Õâ¸öÍæ¼ÒÒÑ¾­µÇ¼Ç¹ıÁË£¬±àºÅÎª£º" + HIW + i + NOR + " ¡£");
			search_viplist(me,player,1);
			return 1;
		
		}
	
		note = allocate_mapping(6);
		note["time"] = time(); 	//Ê±¼ä
		note["wiz"] = me->query("id"); //´¦ÀíÎ×Ê¦
		note["player"] = player+"@"+site; //¹ó±öID¾
		note["mail"] = mail; 	//¹ó±öĞÅÏä
		note["day"] = sprintf("%d",day); 	//¹ó±öÊ±¼ä
		note["renew"] = NULL;	//ÊÇ·ñĞø·Ñ
		
        if( !pointerp(notes) || !sizeof(notes) )
                notes = ({ note });
        else
                notes += ({ note });
		save();
		write("Äã°Ñ " + HIY + player + "@" + site + NOR + " ³É¹¦µØÁĞÈëVIP×Ü¹ÜÀíÃûµ¥£¬¸ÃÍæ¼Ò×¢²áĞÅÏäÎª "+HIY+mail+NOR"£¬¹ó±öÓĞĞ§ÆÚÎª "+HIY+day+NOR+" Ìì¡£\n");
		return 1;
	}

	if (sscanf(arg, "-d %d", num)== 1) {
		if ( wiz_level(me)<4 )
			return notify_fail("Ö»ÓĞarch²Å¿ÉÒÔÉ¾³ıVIP×Ü¹ÜÀíÃûµ¥ÉÏµÄÄÚÈİ¡£ \n");
		if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
			return notify_fail("VIP×Ü¹ÜÀíÃûµ¥ÉÏÃ»ÓĞÕâ¸ö±àºÅµÄÄÚÈİ¡£\n");
		num--;
		notes = notes[0..num-1] + notes[num+1..<1];
		save();
		write("µÚ "+HIY+ (num+1) +NOR+ " ºÅVIP×Ü¹ÜÀíÃûµ¥µÄÄÚÈİÒÑ¾­É¾³ı¡£\n");
		return 1;
	}

	if (sscanf(arg, "-r %d %d", num, renew)== 2) {
		if ( wiz_level(me)<4 )
			return notify_fail("Ö»ÓĞarch²Å¿ÉÒÔĞŞ¸ÄVIP×Ü¹ÜÀíÃûµ¥ÉÏµÄÄÚÈİ¡£ \n");
		if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
			return notify_fail("VIP×Ü¹ÜÀíÃûµ¥ÉÏÃ»ÓĞÕâ¸ö±àºÅµÄÄÚÈİ¡£\n");
		notes[num-1]["renewwiz"]=me->query("id");
		notes[num-1]["renew"]=renew;
		save();
		write("µÚ "+HIY+ (num) + NOR+" ºÅVIP×Ü¹ÜÀíÃûµ¥µÄĞø·ÑÒÑ¾­Íê±Ï¡£\n");
		return 1;
	}


	write("Óï·¨´íÎó£¬Çëhelp addvip¡£\n");
	return 1;
}

string query_save_file()
{
	return VIP_FILE ;
}


void list_viplist(object me, int num)
{
	int i;
	string str;

	i = sizeof(notes);
	if( i < 1 ) write("Êé½£VIP×Ü¹ÜÀíÃûµ¥Ä¿Ç°Ã»ÓĞÈÎºÎÄÚÈİ¡£\n");
	else {
		str="Êé½£VIP×Ü¹ÜÀíÃûµ¥£º\n";
		str += repeat_string("©¥", 55) + "\n";
		while (i-- && (i>=sizeof(notes)-num || num==0)) {
			str += sprintf("%3d %s %-12sĞÅÏä£º%-=20s ÈÕÆÚ£º%s Ìì   ´¦ÀíÎ×Ê¦£º%s£¬%s\n",
				i+1,
				ctime(notes[i]["time"])[4..15],
				capitalize(notes[i]["player"]),
				notes[i]["mail"],
				notes[i]["day"],
				capitalize(notes[i]["wiz"]),
				notes[i]["renew"]?
					("Ğø·Ñ£º"+notes[i]["renew"]+
						" Ìì Ğø·ÑÎ×Ê¦£º"+capitalize(notes[i]["renewwiz"]))
					:"¸ÃÍæ¼ÒÃ»ÓĞĞø·Ñ"
			);
			str += repeat_string("©¥", 55) + "\n";
		}
	}
	me->start_more( str );
}

int search_mail(string mail)
{
    int i;
    if( !(i = sizeof(notes)) ) return 0;
    for( ; i > 0; i-- ) 
	if( notes[i-1]["mail"] == mail ) break;
    return i;
}

int search_player(string player,string site)
{
    int i;
    if( !(i = sizeof(notes)) ) return 0;
    for( ; i > 0; i-- ) 
	if ((strsrch(notes[i-1]["player"],player) > -1) && (strsrch(notes[i-1]["player"],site) > -1 ))break;
    return i;
}


void do_read(object me, int i) 
{
    string s;
    if( i > sizeof(notes) || i < 1) {
	write("Êé½£VIP×Ü¹ÜÀíÃûµ¥ÖĞÎŞ´Ë±àºÅ!!\n");
	return;
    }
    s="Êé½£VIP×Ü¹ÜÀíÃûµ¥±àºÅ£º"+HIG+i+NOR+"\n";
    s += repeat_string("©¥", 55) + "\n";
    s += sprintf("%3d %s %-12sĞÅÏä£º%-=20s ÈÕÆÚ£º%s Ìì   ´¦ÀíÎ×Ê¦£º%s£¬%s\n",
				i,
				ctime(notes[i-1]["time"])[4..15],
				capitalize(notes[i-1]["player"]),
				notes[i-1]["mail"],
				notes[i-1]["day"],
				capitalize(notes[i-1]["wiz"]),
				notes[i-1]["renew"]?
					("Ğø·Ñ£º"+notes[i-1]["renew"]+
						" Ìì Ğø·ÑÎ×Ê¦£º"+capitalize(notes[i-1]["renewwiz"]))
					:"¸ÃÍæ¼ÒÃ»ÓĞĞø·Ñ"
			);
    s += repeat_string("©¥", 55) + "\n";
			
    me->start_more(s);
}
void search_viplist(object me, string arg, int flag)
{
	int i;
	string str,str2;
	str2 = "";

	i = sizeof(notes) -1;
	if( i < 0 ) write("Êé½£VIP×Ü¹ÜÀíÃûµ¥Ä¿Ç°Ã»ÓĞÈÎºÎÄÚÈİ£¬ÎŞ·¨½øĞĞËÑË÷¡£\n");
	else {
		str="Êé½£VIP×Ü¹ÜÀíÃûµ¥£¬Äúµ±Ç°ËÑË÷µÄ¹Ø¼ü×ÖÊÇ£º" + HIY + arg + NOR"\n";
		str += repeat_string("©¥", 55) + "\n";
		while (i>=0) {
			
			if (notes[i]["mail"] == arg){
			str2 += sprintf("%3d %s %-12sĞÅÏä£º"HBRED+HIY"%-=20s "+NOR+"ÈÕÆÚ£º%s Ìì   ´¦ÀíÎ×Ê¦£º%s£¬%s\n",
				i+1,
				ctime(notes[i]["time"])[4..15],
				capitalize(notes[i]["player"]),
				notes[i]["mail"],
				notes[i]["day"],
				capitalize(notes[i]["wiz"]),
				notes[i]["renew"]?
					("Ğø·Ñ£º"+notes[i]["renew"]+
						" Ìì Ğø·ÑÎ×Ê¦£º"+capitalize(notes[i]["renewwiz"]))
					:"¸ÃÍæ¼ÒÃ»ÓĞĞø·Ñ"
			);
			str2 += repeat_string("©¥", 55) + "\n";
		}
		
			if (strsrch(notes[i]["player"],arg) > -1 && flag){
			str2 += sprintf("%3d %s %-12sĞÅÏä£º%-=20s ÈÕÆÚ£º%s Ìì   ´¦ÀíÎ×Ê¦£º%s£¬%s\n",
				i+1,
				ctime(notes[i]["time"])[4..15],
				HBRED+HIY+capitalize(notes[i]["player"])+NOR,
				notes[i]["mail"],
				notes[i]["day"],
				capitalize(notes[i]["wiz"]),
				notes[i]["renew"]?
					("Ğø·Ñ£º"+notes[i]["renew"]+
						" Ìì Ğø·ÑÎ×Ê¦£º"+capitalize(notes[i]["renewwiz"]))
					:"¸ÃÍæ¼ÒÃ»ÓĞĞø·Ñ"
			);
			str2 += repeat_string("©¥", 55) + "\n";			
		}
		i--;
		}
		if (str2==""){
			str += "Ã»ÓĞÕÒµ½ÓÃ " + arg + " ÎªĞÅÏäµÄ¹ó±öÍæ¼Ò¡£\n";
			str += "ÇëÈ·ÈÏ¸ÃĞÅÏäÊÇ·ñÎªÕıÊ½½É·ÑĞÅÏä£¬Èç¹ûÊÇ£¬ÇëÏÈµÇ¼Ç£¬È»ºóÔÚÓÎÏ·ÖĞ¼ÓÍæ¼ÒµÄ¹ó±öÊ±¼ä¡£\n";
			str += repeat_string("©¥", 55) + "\n";	
		}
		else
			str = str + str2;	
	}
		me->start_more( str );
}

int help(object me)
{
        write(@HELP
Ö¸Áî¸ñÊ½ :
addvip [site] [player] [mail] [day] Ôö¼ÓĞÂÍæ¼Òµ½ Êé½£VIP¹ÜÀí ×ÜÁĞ±í
site 	ÊÇËùÔÚÊé½£Õ¾µã£¬µ±Ç°Ö»ÔÊĞí LN,LN2,BX,TY,CQÕâ¼¸¸öÕ¾µÄÍæ¼Ò 
player 	ÊÇÍæ¼ÒID
mail	ÊÇÍæ¼ÒÉêÇë¹ó±öÊ±ºòµÄÓĞĞ§°ÙĞÕEmail
day	ÊÇÍæ¼ÒµÄ¹ó±öÓĞĞ§ÆÚ

addvip [num] ²é¿´¾ßÌåÄ³¸ö±àºÅµÄ¾ßÌå
num	ÊÇÁĞ±íÖĞµÄ±àºÅ

addvip [key] -m °´ÕÕkeyÎª¹Ø¼ü×Ö£¬²éÕÒÓĞÃ»ÓĞÊ¹ÓÃ[key]Îª×¢²áĞÅÏäµÄÍæ¼Ò¡£
addvip [key] -p °´ÕÕkeyÎª¹Ø¼ü×Ö£¬²éÕÒÓĞÃ»ÓĞÊ¹ÓÃ[key]µÄÍæ¼Ò¡£

addvip -d [num] É¾³ıÒ»Ìõ¼ÇÂ¼
num	ÊÇÁĞ±íÖĞµÄ±àºÅ

addvip -r [num] [day] Ğø·Ñ¹ı³Ì
num	ÊÇÁĞ±íÖĞµÄ±àºÅ
day	ÊÇĞø·ÑµÄ¾ßÌåÊ±¼ä

HELP);
 
        return 1;
}
