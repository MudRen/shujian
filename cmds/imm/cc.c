// cc.c

#include <ansi.h>

int main(object me, string arg)
{
        if (!arg) return 0;
        
        /*  Foreground Colors  */

	arg = replace_string(arg, "$BLK$", BLK);		/* Black   */
	arg = replace_string(arg, "$RED$", RED);		/* Red     */
	arg = replace_string(arg, "$GRN$", GRN);		/* Green   */
	arg = replace_string(arg, "$YEL$", YEL);		/* Yellow  */
	arg = replace_string(arg, "$BLU$", BLU);		/* Blue    */
	arg = replace_string(arg, "$MAG$", MAG);		/* Magenta */
	arg = replace_string(arg, "$CYN$", CYN);		/* Cyan    */
	arg = replace_string(arg, "$WHT$", WHT);		/* White   */

	/*  Hi Intensity Foreground Colors  */

	arg = replace_string(arg, "$HIR$", HIR);		/* Red     */
	arg = replace_string(arg, "$HIG$", HIG);		/* Green   */
	arg = replace_string(arg, "$HIY$", HIY);		/* Yellow  */
	arg = replace_string(arg, "$HIB$", HIB);		/* Blue    */
	arg = replace_string(arg, "$HIM$", HIM);		/* Magenta */
	arg = replace_string(arg, "$HIC$", HIC);		/* Cyan    */
	arg = replace_string(arg, "$HIW$", HIW);		/* White   */

        /*  Background Colors  */

	arg = replace_string(arg, "$BBLK$", BBLK);		/* Black   */
	arg = replace_string(arg, "$BRED$", BRED);		/* Red     */
	arg = replace_string(arg, "$BGRN$", BGRN);		/* Green   */
	arg = replace_string(arg, "$BYEL$", BYEL);		/* Yellow  */
	arg = replace_string(arg, "$BBLU$", BBLU);		/* Blue    */
	arg = replace_string(arg, "$BMAG$", BMAG);		/* Magenta */
	arg = replace_string(arg, "$BCYN$", BCYN);		/* Cyan    */

	/*  Hi Intensity Background Colors  */

	arg = replace_string(arg, "$HBRED$", HBRED);	/* Red     */
	arg = replace_string(arg, "$HBGRN$", HBGRN);	/* Green   */
	arg = replace_string(arg, "$HBYEL$", HBYEL);	/* Yellow  */
	arg = replace_string(arg, "$HBBLU$", HBBLU);	/* Blue    */
	arg = replace_string(arg, "$HBMAG$", HBMAG);	/* Magenta */
	arg = replace_string(arg, "$HBCYN$", HBCYN);	/* Cyan    */

	arg = replace_string(arg, "$NOR$", NOR);	/* Puts everything back to normal */

	/*  Additional  */

	arg = replace_string(arg, "$U$", U);		/* Initialize underscore mode */		
	arg = replace_string(arg, "$BLINK$", BLINK);	/* Initialize blink mode */
        arg = replace_string(arg, "$BEEP$", "");
        arg += NOR;
        seteuid(getuid());
        return me->force_me(arg);
}

int help(object me)
{
        write(@HELP
ָ���ʽ : cc ����
 
���ָ�������������������ɫ��

HELP
"                     $NOR$ - �ָ�������ɫ\n"
"$RED$ - "RED"��ɫ"NOR"         $HIR$ - "HIR"����ɫ\n"NOR
"$GRN$ - "GRN"��ɫ"NOR"         $HIG$ - "HIG"����ɫ\n"NOR
"$YEL$ - "YEL"����ɫ"NOR"       $HIY$ - "HIY"��ɫ\n"NOR
"$BLU$ - "BLU"����ɫ"NOR"       $HIB$ - "HIB"��ɫ\n"NOR
"$MAG$ - "MAG"ǳ��ɫ"NOR"       $HIM$ - "HIM"�ۺ�ɫ\n"NOR
"$CYN$ - "CYN"����ɫ"NOR"       $HIC$ - "HIC"����ɫ\n"NOR
"$WHT$ - ǳ��ɫ       $HIW$ - "HIW"��ɫ\n"NOR
@HELP 

����ϵͳ�Զ������ִ�β�˼�һ�� $NOR$��
HELP
);
        return 1;
}
